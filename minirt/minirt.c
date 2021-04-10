#include "minirt.h"
#include "event.h"
#include <time.h>

static void	init_screen(t_screen *screen)
{
	screen->width = 1600; //  -> parse
	screen->height = 900; //  -> parse
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, screen->width, screen->height, "Hellow World!");
	screen->ptr = mlx_new_image(screen->mlx, screen->width, screen->height); // 이미지 객체 생성
	screen->addr = mlx_get_data_addr(screen->ptr, &screen->bits_per_pixel, &screen->line_length, &screen->endian); // 이미지 주소 할당
}

static void	event(t_minirt *mini)
{
	mlx_key_hook(mini->scr.win, key_hook, &mini->scr); // esc close
	mlx_hook(mini->scr.win, 17, 0, exit_hook, 0); // x button close
}

static void draw(t_screen *screen)
{
	mlx_put_image_to_window(screen->mlx, screen->win, screen->ptr, 0, 0); // 생성한 이미지 객체 윈도우에 올리기
	mlx_loop(screen->mlx);
}

static int	minirt(t_minirt *mini)
{
	clock_t start, end;		// time check

	init_screen(&mini->scr);
	event(mini);
	start = clock();		// time check
	render(mini);
	end = clock();		// time check
	printf("time : %f\n",(double)(end - start) / CLOCKS_PER_SEC);
	draw(&mini->scr);
	return (0);
}

int		main()
{
	t_minirt	mini;

	//parsing();
	//parsing 에러 체크
	mini.wrd = init_world();
	world_add(mini.wrd, init_sphere(vec(0, 0, -1), 0.5), hit_sphere);	// 원래 구
	world_add(mini.wrd, init_sphere(vec(0, -100.5, -1), 100), hit_sphere);	// 원래 구
	mini.cam = malloc(sizeof(t_camera) * 1); // -> parse needed
	set_camera((&mini.cam[0]), vec(0, 0, 0), 2.0, (16.0 / 9.0)); // -> parse
	minirt(&mini);
	//minirt 에러 체크
	return (0);
}
