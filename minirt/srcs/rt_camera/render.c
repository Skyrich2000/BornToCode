#include "minirt.h"


static void	put_pixel(t_screen *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	ray_color(t_world *world, t_ray *ray)
{
	t_vec p;
	t_vec n;
	double t;
	t_hit_record rec;

	if (world_hit(world->next, ray, (double[2]){0, 99999999}, &rec))
	{
		// p = ray_at(ray, t);
		// n = vec_cal((t_vec[2]){p, center}, (double[2]){1, -1}, 2);
		n = rec.n; // unit_vector 변환은 hit_sphere 에서 처리
		return (trgb(0, 255 * ((n.x + 1) / 2), 255 * ((n.y + 1) / 2), 255 * ((n.z + 1) / 2)));
	}
	n = vec_unit(&ray->dir);
	t = 1-0.5 * (n.y + 1.0);
	return (trgb(0, 255 * (1-t + 0.5*t),255 * (1-t + 0.7*t) ,255 * (1-t + 1.0*t)));
}

int	render(t_screen *screen, t_world *world, t_camera *cam)
{
	int			hdx;
	int			wdx;
	double		u;
	double		v;
	t_ray 		ray;

	hdx = -1;
	while (++hdx < (screen->height - 1))
	{
		wdx = -1;
		while (++wdx < (screen->width - 1))
		{
			v = (double)hdx / (screen->height  - 1);
			u = (double)wdx / (screen->width - 1);
			ray.origin = cam->pos;
			ray.dir = vec_cal((t_vec[3]){cam->low_left_corner, cam->horizon, cam->vertical} \
							, (double[3]){1, u, v}, 3);
			put_pixel(screen, wdx, hdx, ray_color(world, &ray)); // 생성한 이미지에 픽셀별 color지정하기
		}
	}
	return (0);
}
