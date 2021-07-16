#include "engine.h"
#include <time.h>

time_t start;

t_game	*g()
{
	static t_game game;

	return (&game);
}

void	init_game()
{
	t_game	*game;
	int		i;

	game = g();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "TENET");
	game->background.img = mlx_new_image(g()->mlx, WIDTH, HEIGHT);
	game->background.addr = mlx_get_data_addr(game->background.img, &game->background.bits_per_pixel, &game->background.line_length, &game->background.endian);
	game->instances = create_list();
	i = 0;
	while (i++ < 127)
		game->keys[i] = 0;
}

int		loop()
{
	static int fps = 0;
	time_t end;
	t_list *node;
	t_instance	*ins;

	fps++;
	time(&end);
	if (start == 0 || (float)(end - start) >= 1.0)
	{
		printf("fps : %d\n", fps);
		fps = 0;
		time(&start);
	}

	node = g()->instances->next;
	while (node)
	{
		ins = (t_instance *)node->data;
		if (ins->step)
			ins->step(ins);
		node = node->next;

	}
	draw_background();
	node = g()->instances->next;
	while (node)
	{
		ins = (t_instance *)node->data;
		if (ins->draw)
			ins->draw(ins);
		node = node->next;
	}
	return (OK);
}

void	start_game()
{
	mlx_hook(g()->win, 2, 0, key_press, 0);
	mlx_hook(g()->win, 3, 0, key_release, 0);
	mlx_loop_hook(g()->mlx, loop, 0);
	mlx_loop(g()->mlx);
}
