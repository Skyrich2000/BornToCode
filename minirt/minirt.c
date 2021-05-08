#include "minirt.h"
#include <time.h>

static void	init_screen(t_screen *screen)
{
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

static double p2p(t_vec p1, t_vec p2)
{
	return (sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2)));
}

static int	minirt(t_minirt *mini)
{
	clock_t start, end;		// time check

	// setting screen
	init_screen(&mini->scr);

	// setting event handler
	event(mini);

	// render first scene
	start = clock();		// time check
	render(mini);
	end = clock();		// time check
	printf("time : %f\n",(double)(end - start) / CLOCKS_PER_SEC);

	// draw screen to window
	draw(&mini->scr);
	return (0);
}

int		main(int argc, char **argv)
{
	t_minirt	mini;

	ft_memset(&mini, 0, sizeof(t_minirt));
	mini.wrd = init_world();
	mini.cam = init_camera();
	if (!input(argc, argv, &mini))
		return (ERROR);
	mini.scr.anti = 0; // -> parse
	mini.curr_cam = mini.cam->next;
	minirt(&mini); //minirt 에러 체크
	// 반지름에서 지름으로 변경
	return (0);
}
