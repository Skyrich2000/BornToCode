/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:06 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:28:03 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_game	*g(void)
{
	static t_game	game;

	return (&game);
}

int	init_game(void)
{
	t_game	*game;
	int		i;

	game = g();
	sl_bzero(game, sizeof(t_game));
	game->view.view_wview = WINDOW_WIDTH;
	game->view.view_hview = WINDOW_HEIGHT;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "TENET");
	game->canvas.img = mlx_new_image(g()->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->canvas.x = 0;
	game->canvas.y = 0;
	game->frame.count = 0;
	game->frame.skip_frame = 0;
	i = -1;
	while (++i < OBJ_SIZE)
		game->instances[i] = create_list();
	i = -1;
	while (++i < 127)
		game->keys[i] = 0;
	mlx_hook(g()->win, 2, 0, key_press, 0);
	mlx_hook(g()->win, 3, 0, key_release, 0);
	mlx_hook(g()->win, 17, 0, exit_press, 0);
	mlx_loop_hook(g()->mlx, loop, 0);
	return (OK);
}

void	loop_instance(void)
{
	int			i;
	t_list		*node;
	t_instance	*ins;

	i = -1;
	while (++i < OBJ_SIZE)
	{
		node = g()->instances[i]->next;
		while (node)
		{
			ins = (t_instance *)node->data;
			node = node->next;
			if (ins->draw)
				ins->draw(ins);
			if (!g()->frame.count && ins->step)
				ins->step(ins);
		}
	}
}

int	loop(void)
{
	if (!g()->frame.count && g()->scene->controller)
		g()->scene->controller();
	g()->canvas.x = g()->view.view_xview;
	g()->canvas.y = g()->view.view_yview;
	draw_background(&g()->canvas);
	draw_background(g()->scene->background);
	loop_instance();
	if (g()->scene->ui)
		g()->scene->ui();
	if (keyboard_check(KEY_P))
		draw_debug();
	if (g()->frame.count)
		g()->frame.count -= 1;
	else
		g()->frame.count = g()->frame.skip_frame;
	mlx_sync(MLX_SYNC_WIN_FLUSH_CMD, g()->win);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, g()->win);
	return (OK);
}

void	start_game(t_scene *scene)
{
	g()->scene = scene;
	g()->scene->start();
	mlx_loop(g()->mlx);
}
