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
/*
static t_vec	random_in_unit_disk(double dist_to_focus)
{
	t_vec	out;

	while (1)
	{
		out = vec(rand_num(1, -1, 1),rand_num(1, -1, 1),0);
		if (vec_length_squared_(&out) >= 1)
			continue ;
		return (vec_cal(&out, &dist_to_focus, 1));
	}
}

static t_clr ray_color_scatter(t_world *world, t_ray *ray, int depth)
{
	t_hit_record	rec;
	t_ray			new_ray;
	double			val_for_sky;
	t_vec			ray_from_cam;

	if (depth <= 0)
		return ((t_vec){0, 0, 0});
	if (hit_world(world, ray, (double [2]){EPSILON, INFINITY}, &rec))
	{
		if (rec.material->scatter(rec.material, ray, &rec, &new_ray))
			return (vec_mul(rec.material->color, \
					ray_color_scatter(world, &new_ray, depth - 1)));
		return (vec(0, 0, 0));
	}
	ray_from_cam = vec_oppo(vec_unit_(&ray->dir));
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}
*/

static t_clr	ray_color(t_ray *ray)
{
	t_hit_record	rec;
	double			val_for_sky;
	t_vec			ray_from_cam;

	if (hit_world(m()->wrd, ray, (double [2]){0.001, INFINITY}, &rec))
		return (phong(&rec));
	ray_from_cam = vec_oppo(vec_unit_(&ray->dir));
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}

static int	anti(const t_camera *cam, int wdx, int hdx)
{
	double	u;
	double	v;
	int		adx;
	t_ray	ray;
	t_clr	color;

	color = vec(0, 0, 0);
	adx = -1;
	while (++adx <= m()->scr.anti)
	{
		u = (double)(wdx + rand_num(m()->scr.anti, 0, 0)) / (m()->scr.wid - 1);
		v = (double)(hdx + rand_num(m()->scr.anti, 0, 0)) / (m()->scr.hei - 1);
		ray.origin = cam->pos;
		ray.dir = vec_cal((t_vec [4]){cam->low_left_corner, \
									  cam->hor, \
									  cam->ver, \
									  cam->pos}, \
						  (double [4]){1, u, v, -1}, \
						  4);
		ray.dir = vec_unit_(&ray.dir);
		color = vec_cal((t_vec [2]){color, ray_color(&ray)}, \
						(double [2]){1, 1}, \
						2);
	}
	return (trgb_anti(&color, m()->scr.anti));
}

void	render_pixel(const t_camera *cam, const int thread_idx[2], int i, int j)
{
	const int	x = (m()->scr.wid / W_THREAD) * thread_idx[1] + j;
	const int	y = (m()->scr.hei / H_THREAD) * thread_idx[0] + i;

	put_pixel(cam, x, m()->scr.hei - y, anti(cam, x, y));
}
