#include "minirt.h"

void print_cam(t_camera *cam);

static void put_pixel(t_minirt *mini, int x, int y, int color)
{
	char *dst;

	dst = mini->curr_cam->img_addr + (y * mini->scr.line_length + x * (mini->scr.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int trgb_anti(t_vec *colors, int anti)
{
	double scale;

	if (anti == 0)
		anti = 1;
	scale = 1 / (double)anti;
	colors->x = clamp((colors->x * scale), 0, 0.999);
	colors->y = clamp((colors->y * scale), 0, 0.999);
	colors->z = clamp((colors->z * scale), 0, 0.999);
	return trgb(0, colors->x * 256, colors->y * 256, colors->z * 256);
}

static t_vec random_in_unit_disk(double dist_to_focus)
{
	t_vec out;
	while(1)
	{
		out = vec(rand_num(1, -1, 1),rand_num(1, -1, 1),0);
		if (vec_length_squared_(&out) >= 1)
			continue;
		return (vec_cal(&out, &dist_to_focus, 1));
	}
}

static t_clr ray_color_scatter(t_world *world, t_ray *ray, int depth)
{
	t_hit_record rec;	// world_hit -> hit = true 면 rec 에 object 위의 점에 대한 정보 기록
	t_ray new_ray;	// target - p ray

	double val_for_sky;	// 하늘색 표현을 위한 값... 아래 변수들은 사실 나중에 없애도 됨
	t_vec ray_from_cam;	// 카메라에서 쏜 방향벡터..

	if (depth <= 0)
		return ((t_vec){0, 0, 0});
	if (hit_world(world, ray, (double[2]){EPSILON, INFINITY}, &rec))
	{
		if (rec.material->scatter(rec.material, ray, &rec, &new_ray))
			return (vec_mul(rec.material->color, ray_color_scatter(world, &new_ray, depth - 1)));
		return (vec(0, 0, 0));
	}
	ray_from_cam = vec_oppo(vec_unit_(&ray->dir));
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}

static t_clr ray_color(t_minirt *mini, t_ray *ray, int depth)
{
	t_hit_record rec;	// world_hit -> hit = true 면 rec 에 object 위의 점에 대한 정보 기록
	t_ray new_ray;	// target - p ray

	double val_for_sky;	// 하늘색 표현을 위한 값... 아래 변수들은 사실 나중에 없애도 됨
	t_vec ray_from_cam;	// 카메라에서 쏜 방향벡터..

	if (depth <= 0)
		return ((t_vec){0, 0, 0});
	if (hit_world(mini->wrd, ray, (double[2]){0.001, INFINITY }, &rec))
		return (phong(mini, &rec));
	ray_from_cam = vec_oppo(vec_unit_(&ray->dir));
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}

static int	anti(t_minirt *mini, int wdx, int hdx)
{
	double	u;
	double	v;
	int		adx;
	t_ray	ray;
	t_clr	color;

	color = vec(0, 0, 0); // color 값 초기화
	adx = -1;
	while (++adx <= mini->scr.anti)
	{
		u = (double)(wdx + rand_num(mini->scr.anti, 0, 0)) / (mini->scr.width - 1);
		v = (double)(hdx + rand_num(mini->scr.anti, 0, 0)) / (mini->scr.height - 1);

		// blur effect
		// t_vec rd = random_in_unit_disk(mini->curr_cam->lens_radius);
		// t_vec offset = vec_cal((t_vec[2]){mini->curr_cam->u, mini->curr_cam->v}, (double[2]){rd.x, rd.y}, 2);  // u * rd.x() + v * rd.y();
		ray.origin = mini->curr_cam->pos;
		ray.dir = vec_cal((t_vec[4]){ mini->curr_cam->low_left_corner,
									  mini->curr_cam->horizon,
									  mini->curr_cam->vertical,
									  mini->curr_cam->pos,
									  },
						  (double[4]){ 1, u, v, -1},
						  4);
		ray.dir = vec_unit_(&ray.dir);
		color = vec_cal((t_vec[2]){ color, ray_color(mini, &ray, MAX_DEPTH) },
						(double[2]){ 1, 1 },
						2);
	}
	return (trgb_anti(&color, mini->scr.anti));
}

int render(t_minirt *mini)
{
	int hdx;
	int wdx;

	// print_cam(mini->curr_cam);
	hdx = -1;
	while (++hdx < (mini->scr.height - 1))
	{
		wdx = -1;
		while (++wdx < (mini->scr.width - 1))
			put_pixel(mini, wdx, (mini->scr.height - 1 - hdx), anti(mini, wdx, hdx));
		// printf("%d / %d (%.f%%)\n", hdx, mini->scr.height, (double)(hdx) / (mini->scr.height) * 100);
	}
	return (0);
}

void print_cam(t_camera *cam)
{
	vec_print("pos", &cam->pos);
	vec_print("horizon", &cam->horizon);
	vec_print("vertical", &cam->vertical);
	vec_print("lowleftcorner", &cam->low_left_corner);
	printf("view_width : %.2f\n", cam->view_width);
	printf("view_height : %.2f\n", cam->view_height);
	// printf("fov : %.2f\n", cam->fov);
	vec_print("u", &cam->u);
	vec_print("v", &cam->v);
	vec_print("w", &cam->w);

}
