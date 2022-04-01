#include "minirt.h"

static void	put_pixel(const t_camera *cam, int x, int y, int color)
{
	char	*dst;

	dst = cam->img_addr + \
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
		if (m()->ray_mode)
			return (phong(&rec));
		if (rec.material->scatter(rec.material, ray, &rec, &new_ray))
			return (vec_mul(get_rec_color(&rec), \
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

void	render_pixel(const t_camera *cam, const int thread_idx[2], int i, int j)
{
	const int	x = (m()->scr.wid / W_THREAD) * thread_idx[1] + j;
	const int	y = (m()->scr.hei / H_THREAD) * thread_idx[0] + i;
	const int	color = anti(cam, x, y, m()->resolution_toggle * m()->scr.anti);
	int			skip_i;
	int			skip_j;

	skip_i = -1;
	while (++skip_i <= m()->scr.lower_resolution)
	{
		skip_j = -1;
		while (++skip_j <= m()->scr.lower_resolution)
			put_pixel(cam, x - skip_j, m()->scr.hei - y + skip_i, color);
	}
}
