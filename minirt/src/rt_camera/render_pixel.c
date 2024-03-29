/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:57:08 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:57:08 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	put_pixel(int x, int y, int color)
{
	char	*dst;

	if (!m()->curr_cam->img_addr)
		return ;
	dst = m()->curr_cam->img_addr + \
		(y * m()->scr.line_length + x * (m()->scr.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	trgb_anti(t_vec *colors, int anti)
{
	double	scale;

	if (anti == 0)
		anti = 1;
	scale = 1 / (double)anti;
	colors->x = clamp((colors->x * scale), 0, 0.999);
	colors->y = clamp((colors->y * scale), 0, 0.999);
	colors->z = clamp((colors->z * scale), 0, 0.999);
	return (trgb(0, colors->x * 256, colors->y * 256, colors->z * 256));
}

static t_clr	ray_color_scatter(t_ray *ray, int depth)
{
	t_hit_record	rec;
	t_ray			new_ray;
	double			val_for_sky;
	t_vec			ray_from_cam;

	if (depth <= 0)
		return ((t_vec){0, 0, 0});
	if (hit_world(ray, (double [2]){EPSILON, INFINITY}, &rec))
	{
		if (m()->ray_mode && !rec.is_material_fixed)
			return (phong(&rec));
		if (rec.material->scatter(rec.material, ray, &rec, &new_ray))
			return (vec_mul(phong(&rec), \
					ray_color_scatter(&new_ray, depth - 1)));
		return (vec(0, 0, 0));
	}
	ray_from_cam = vec_oppo(vec_unit_(&ray->dir));
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}

static int	anti(const t_camera *cam, int wdx, int hdx, int level)
{
	double	u;
	double	v;
	int		adx;
	t_ray	ray;
	t_clr	color;

	color = vec(0, 0, 0);
	adx = -1;
	while (++adx <= level)
	{
		u = (double)(wdx + rand_num(level, 0, 0)) / (m()->scr.wid - 1);
		v = (double)(hdx + rand_num(level, 0, 0)) / (m()->scr.hei - 1);
		ray.origin = cam->pos;
		ray.dir = vec_cal((t_vec [4]){cam->low_left_corner, \
										cam->hor, \
										cam->ver, \
										cam->pos}, \
						(double [4]){1, u, v, -1}, \
						4);
		ray.dir = vec_unit_(&ray.dir);
		color = vec_cal((t_vec [2]){color, ray_color_scatter(&ray, MAX_DEPTH)}, \
						(double [2]){1, 1}, \
						2);
	}
	return (trgb_anti(&color, level));
}

void	render_pixel(int x, int y)
{
	int			color;
	int			skip_y;
	int			skip_x;

	color = anti(m()->curr_cam, x, y, m()->resolution_toggle * m()->scr.anti);
	skip_y = -1;
	while (++skip_y <= m()->scr.lower_resolution)
	{
		skip_x = -1;
		while (++skip_x <= m()->scr.lower_resolution)
			if (0 <= x && x + skip_x < m()->scr.wid \
				&& 0 <= y && y + skip_y < m()->scr.hei)
				put_pixel(x + skip_x, m()->scr.hei - (y + skip_y), color);
	}
}
