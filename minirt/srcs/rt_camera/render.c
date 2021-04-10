#include "minirt.h"

static void put_pixel(t_screen *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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

static t_vec ray_color(t_world *world, t_ray *ray, int depth)
{
	t_vec target;
	t_hit_record rec;	// world_hit -> hit = true 면 rec 에 object 위의 점에 대한 정보 기록
	t_ray tmp;	// target - p ray

	double val_for_sky;	// 하늘색 표현을 위한 값... 아래 변수들은 사실 나중에 없애도 됨
	t_vec ray_from_cam;	// 카메라에서 쏜 방향벡터..

	if (depth <= 0)
		return ((t_vec){0, 0, 0}); // ?! 이런게 됨?? - huni
	if (world_hit(world, ray, (double[2]){ 0.001, INFINITY }, &rec))
	{
		target = vec_cal((t_vec[2]){rec.p, random_in_hemisphere(&rec.n)}, (double[2]){1, 1} ,3);
		tmp.origin = rec.p; // random value에 의한 정점좌표를 새로 지정
		tmp.dir = vec_cal((t_vec[2]){target, rec.p},(double[2]){1, -1} ,2);
		return (vec_cal((t_vec[1]){ray_color(world, &tmp, depth - 1)}, (double[1]){0.5}, 1));
	}
	ray_from_cam = vec_unit(&ray->dir);
	val_for_sky = 0.5 - 0.5 * ray_from_cam.y;
	return (vec((1 - 0.5 * val_for_sky), (1 - 0.3 * val_for_sky), 1));
}

static int	anti(t_minirt *mini, int wdx, int hdx)
{
	double	u;
	double	v;
	int		adx;
	t_ray	ray;
	t_vec	color;

	color = vec(0, 0, 0); // color 값 초기화
	adx = -1;
	while (++adx <= mini->scr.anti)
	{
		u = (double)(wdx + rand_num(mini->scr.anti, 0, 0)) / (mini->scr.width - 1);
		v = (double)(hdx + rand_num(mini->scr.anti, 0, 0)) / (mini->scr.height - 1);
		ray.origin = mini->cam->pos;
		ray.dir = vec_cal((t_vec[3]){ mini->cam->low_left_corner,
									  mini->cam->horizon,
									  mini->cam->vertical },
						  (double[3]){ 1, u, v },
						  3);
		color = vec_cal((t_vec[2]){ color, ray_color(mini->wrd, &ray, MAX_DEPTH) },
						(double[2]){ 1, 1 },
						2); // line break ..? - huni
	}
	return (trgb_anti(&color, mini->scr.anti));
}

int render(t_minirt *mini)
{
	int hdx;
	int wdx;

	hdx = -1;
	while (++hdx < (mini->scr.height - 1))
	{
		wdx = -1;
		while (++wdx < (mini->scr.width - 1))
			put_pixel(&mini->scr, wdx, (mini->scr.height - 1 - hdx), anti(mini, wdx, hdx));
	}
	return (0);
}
