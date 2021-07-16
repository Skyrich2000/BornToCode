/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:06 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 03:11:04 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	i = -1;
	while (++i < OBJ_SIZE)
		game->instances[i] = create_list();
	i = -1;
	while (++i < 127)
		game->keys[i] = 0;
}

int		loop()
{
	int i;
	static int fps = 0;
	time_t end;
	t_list *node;
	t_instance	*ins;

	// fps 출력하는 함수
	fps++;
	time(&end);
	if (start == 0 || (float)(end - start) >= 1.0)
	{
		printf("fps : %d\n", fps);
		fps = 0;
		time(&start);
	}

	// step
	i = -1;
	while (++i < OBJ_SIZE)
	{
		node = g()->instances[i]->next;
		while (node)
		{
			ins = (t_instance *)node->data;
			if (ins->step)
				ins->step(ins);
			node = node->next;
		}
	}
	// draw
	draw_background();
	i = -1;
	while (++i < OBJ_SIZE)
	{
		node = g()->instances[i]->next;
		while (node)
		{
			ins = (t_instance *)node->data;
			if (ins->draw)
				ins->draw(ins);
			node = node->next;
		}
	}
	return (OK);
}

void	start_game()
{
	mlx_hook(g()->win, 2, 0, key_press, 0);
	mlx_hook(g()->win, 3, 0, key_release, 0);
	mlx_hook(g()->win, 17, 0, exit_press, 0);
	mlx_loop_hook(g()->mlx, loop, 0);
	mlx_loop(g()->mlx);
}
