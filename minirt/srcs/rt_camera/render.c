#include "minirt.h"

static void put_pixel(t_screen *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static double clamp(double n, double min, double max)
{
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}
/******************** antialiasing  start *********************/
static int trgb_anti(t_vec *colors, int anti)
{
	double scale;

	if (anti == 0)
		anti = 1;
	scale = 1 / (double)anti;
	colors->x = clamp(sqrt(colors->x * scale), 0, 0.999);
	colors->y = clamp(sqrt(colors->y * scale), 0, 0.999);
	colors->z = clamp(sqrt(colors->z * scale), 0, 0.999);

	// printf("R, G, B : [%d, %d, %d]\n",(int)colors->x, (int)colors->y, (int)colors->z);
	return trgb(0, colors->x * 256, colors->y * 256, colors->z * 256);
}
/******************** antialiasing  end   *********************/


// static int ray_color(t_world *world, t_ray *ray, int depth)
// {
// 	t_vec target;
// 	t_vec n;
// 	double t;
// 	t_hit_record rec;

// 	if (world_hit(world, ray, (double[2]){ 0, 99999999 }, &rec))
// 	{
// 		// p = ray_at(ray, t);
// 		// n = vec_cal((t_vec[2]){p, center}, (double[2]){1, -1}, 2);
// 		n = rec.n; // unit_vector 변환은 hit_sphere 에서 처리
// 		return (trgb(0, 255 * ((n.x + 1) / 2), 255 * ((n.y + 1) / 2), 255 * ((n.z + 1) / 2)));
// 	}
// 	n = vec_unit(&ray->dir);
// 	t = 1 - 0.5 * (n.y + 1.0);
// 	return (trgb(0, 255 * (1 - t + 0.5 * t), 255 * (1 - t + 0.7 * t), 255 * (1 - t + 1.0 * t)));
// }

/********************  ray_color를 구조체 리턴하도록 바꿔본거 ***********************/
static t_vec ray_color_tvec(t_world *world, t_ray *ray, int depth)
{
	t_vec p;
	t_vec n;
	double t;
	t_vec out;	// R, G, B 값을 가지고 있는 구조체!
	t_hit_record rec;	// world_hit -> hit = true 면 rec 에 object 위의 점에 대한 정보 기록
	t_ray tmp;

	if (depth <= 0)
		return ((t_vec){0, 0, 0});

	if (world_hit(world, ray, (double[2]){ 0.001, INFINITY }, &rec))
	{
		n = rec.n; // unit_vector 변환은 hit_sphere 에서 처리
		// out = vec(255 * ((n.x + 1) / 2), 255 * ((n.y + 1) / 2), 255 * ((n.z + 1) / 2));
		p = vec_cal((t_vec[3]){rec.p, rec.n, random_unit_vector()}, (double[3]){1, 1, 1} ,3);
		tmp.origin = rec.p; // random value에 의한 정점좌표를 새로 지정
		tmp.dir = vec_cal((t_vec[2]){p, rec.p},(double[2]){1, -1} ,2);
		// return (out);
		return (vec_cal((t_vec[1]){ray_color_tvec(world, &tmp, depth - 1)}, (double[1]){0.5}, 1));
	}
	n = vec_unit(&ray->dir);
	t = 1 - 0.5 * (n.y + 1.0);
	out = vec((1 - 0.5 * t), (1 - 0.3 * t), 1);
	return (out);
}
/********************  ray_color를 구조체 리턴하도록 바꿔본거 ***********************/


// int render(t_screen *screen, t_world *world, t_camera *cam)
// {
// 	int hdx;
// 	int wdx;
// 	double u;
// 	double v;
// 	t_ray ray;

// 	int anti = 100; // 여기서
// 	int adx;
// 	t_vec color; // 이까지 추가..

// 	hdx = -1;
// 	while (++hdx < (screen->height - 1))
// 	{
// 		wdx = -1;
// 		while (++wdx < (screen->width - 1))
// 		{
// 			adx = -1;
// 			color = vec(0, 0, 0); // color 값 초기화
// 			while(++adx < anti)
// 			{
// 				u = (double)(wdx + rand_num()) / (screen->width - 1);
// 				v = (double)(hdx + rand_num()) / (screen->height - 1);
// 				ray.origin = cam->pos;
// 				ray.dir = vec_cal((t_vec[3]){ cam->low_left_corner, cam->horizon, cam->vertical },
// 									(double[3]){ 1, u, v },
// 									3);
// 				color = vec_cal((t_vec[3]){color, ray_color_tvec(world, &ray)}, (double[2]){1, 1}, 2);
// 			}
// 			put_pixel(screen, wdx, (screen->height - 1- hdx), trgb_anti(&color, anti));
// 			// put_pixel(screen, wdx, hdx, ray_color(world, &ray)); // 생성한 이미지에 픽셀별 color지정하기å
// 		}
// 	}
// 	return (0);
// }

int	render(t_screen *screen, t_world *world, t_camera *cam)
{
	int			idx;
	double		u;
	double		v;
	t_ray		ray;

	int anti = 50; // 여기서 (안티앨리어싱)
	int adx;
	t_vec color; // 이까지 추가..
	int max_depth = 50;		// 추가 (매트)

	idx = -1;
	while (++idx < (screen->height - 1) * (screen->width - 1))
	{
		adx = -1;
		color = vec(0, 0, 0);
		while (++adx <= anti)
		{
			u = (double)((idx % (screen->width - 1)) + rand_num(anti, 0, 0)) / (screen->width - 1);
			v = (double)((screen->height - (idx / (screen->width - 1))) + rand_num(anti, 0, 0)) / (screen->height - 1);
			ray.origin = cam->pos;
			ray.dir = vec_cal((t_vec[3]){cam->low_left_corner, cam->horizon, cam->vertical} \
							, (double[3]){1, u, v}, 3);
			color = vec_cal((t_vec[2]){color, ray_color_tvec(world, &ray, max_depth)}, (double[2]){1, 1}, 2);
		}
		put_pixel(screen, idx % (screen->width - 1), (idx / (screen->width - 1)), trgb_anti(&color, anti));
		// put_pixel(screen, idx % (screen->width - 1), idx / (screen->width - 1), ray_color(world, &ray)); // 생성한 이미지에 픽셀별 color지정하기
	}
	return (0);
}
