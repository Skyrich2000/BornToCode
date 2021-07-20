/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:06 by ycha              #+#    #+#             */
/*   Updated: 2021/07/20 22:54:20 by ycha             ###   ########.fr       */
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

// TODO: free list if malloc failed
int		init_game()
{
	t_game	*game;
	int		i;

	game = g();
	sl_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "TENET");
	i = -1;
	while (++i < OBJ_SIZE)
	{
		game->instances[i] = create_list();
		if (!game->instances[i])
			return (ERROR);
	}
	i = -1;
	while (++i < 127)
		game->keys[i] = 0;
	mlx_hook(g()->win, 2, 0, key_press, 0);
	mlx_hook(g()->win, 3, 0, key_release, 0);
	mlx_hook(g()->win, 17, 0, exit_press, 0);
	mlx_loop_hook(g()->mlx, loop, 0);
	return (OK);
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
	if (g()->scene->controller)
		g()->scene->controller();
	while (++i < OBJ_SIZE)
	{
		node = g()->instances[i]->next;
		while (node)
		{
			ins = (t_instance *)node->data;
			node = node->next;
			if (ins->step)
				ins->step(ins);
		}
	}
	// draw
	i = -1;
	draw_background(g()->scene->background);
	while (++i < OBJ_SIZE)
	{
		node = g()->instances[i]->next;
		while (node)
		{
			ins = (t_instance *)node->data;
			node = node->next;
			if (ins->draw)
				ins->draw(ins);
		}
	}
	if (keyboard_check(KEY_P))
		draw_debug();
	return (OK);
}

void	start_game(t_scene *scene)
{
	g()->scene = scene;
	if (scene->start)
		scene->start();
	mlx_loop(g()->mlx);
}
