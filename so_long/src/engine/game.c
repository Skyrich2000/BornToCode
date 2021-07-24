/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:06 by ycha              #+#    #+#             */
/*   Updated: 2021/07/24 18:44:49 by ycha             ###   ########.fr       */
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
	game->view.view_wview = WINDOW_WIDTH;
	game->view.view_hview = WINDOW_HEIGHT;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "VENEV");
	game->canvas.img = mlx_new_image(g()->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->canvas.x = 0;
	game->canvas.y = 0;
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

static void	print_fps()
{
	static int	fps = 0;
	time_t		end;

	fps++;
	time(&end);
	if (start == 0 || (float)(end - start) >= 1.0)
	{
		printf("fps : %d\n", fps);
		fps = 0;
		time(&start);
	}
}

int		loop()
{
	int			i;
	t_list		*node;
	t_instance	*ins;

	print_fps();
	i = -1;
	if (g()->scene->controller)
		g()->scene->controller();
	g()->canvas.x = g()->view.view_xview;
	g()->canvas.y = g()->view.view_yview;
	draw_background(&g()->canvas);
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
			if (ins->step)
				ins->step(ins);
		}
	}
	if (g()->scene->ui)
		g()->scene->ui();
	if (keyboard_check(KEY_P))
		draw_debug();
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, g()->win);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, g()->win);
	return (OK);
}

void	start_game(t_scene *scene)
{
	g()->scene = scene;
	if (scene->start)
		scene->start();
	mlx_loop(g()->mlx);
}
