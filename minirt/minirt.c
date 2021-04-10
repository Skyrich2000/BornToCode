#include "minirt.h"
#include "event.h"
#include <time.h>

static void init(t_screen *screen)
{
	screen->width = 1600; //  -> parse
	screen->height = 900; //  -> parse
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, screen->width, screen->height, "Hellow World!");
	screen->ptr = mlx_new_image(screen->mlx, screen->width, screen->height); // 이미지 객체 생성
	screen->addr = mlx_get_data_addr(screen->ptr, &screen->bits_per_pixel, &screen->line_length, &screen->endian); // 이미지 주소 할당
}

static void event(t_screen *screen, t_world *world, t_camera *cam)
{
	mlx_key_hook(screen->win, key_hook, screen); // esc close
	mlx_hook(screen->win, 17, 0, exit_hook, 0); // x button close
}

static void draw(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->win, screen->ptr, 0, 0); // 생성한 이미지 객체 윈도우에 올리기
	mlx_loop(screen->mlx);
}

int minirt(t_screen *screen, t_world *world, t_camera *cam)
{
	clock_t start, end;

	init(screen);
	event(screen, world, cam);
	start = clock();		// time check
	render(screen, world, cam + 0);
	end = clock();		// time check
	printf("time : %f\n",(double)(end - start) / CLOCKS_PER_SEC);
	draw(screen);
	return (0);
}

int		main()
{
	t_screen	screen;
	t_world		*world;
	t_camera	*cam;

	//parsing();
	//parsing 에러 체크
	world = init_world();
	world_add(world, init_sphere(vec(0, 0, -1), 0.5), hit_sphere);	// 원래 구
	world_add(world, init_sphere(vec(0, -100.5, -1), 100), hit_sphere);	// 원래 구
	cam = malloc(sizeof(t_camera) * 1); // -> parse needed
	set_camera(&(cam[0]), vec(0, 0, 0), 2.0, (16.0 / 9.0)); // -> parse
	minirt(&screen, world, cam);
	//minirt 에러 체크
	return (0);
}


// hi zzz..
/*
	double i = 0.0;
	for (int k = 0 ; k < 4 ; ++k)
	{
		world_add(world, set_sphere(vec(-0.1, i, -1), 0.08), hit_sphere);
		world_add(world, set_sphere(vec(-0.58, i, -1), 0.08), hit_sphere);
		i += 0.2;
	}
	world_add(world, set_sphere(vec(-0.26, 0.3, -1), 0.08), hit_sphere);
	world_add(world, set_sphere(vec(-0.42, 0.3, -1), 0.08), hit_sphere);
	for (int k = 0 ; k < 5 ; ++k)
	{
		i -= 0.16;
		if (k == 1)
			continue;
		world_add(world, set_sphere(vec(0.15, i, -1), 0.08), hit_sphere);
	}
*/
