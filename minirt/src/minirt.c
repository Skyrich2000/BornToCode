/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:24:28 by ycha              #+#    #+#             */
/*   Updated: 2022/04/01 21:57:23 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	loop_hook(void)
{
	key_camera_move();
	set_gui(m()->curr_cam);
	if (m()->render_refresh)
		render();
	m()->render_refresh = 0;
	if (m()->curr_cam->img)
		mlx_put_image_to_window(\
					m()->scr.mlx, \
					m()->scr.win, \
					m()->curr_cam->img, 0, 0);
	if (m()->gui_toggle)
		draw_gui();
	mlx_do_sync(m()->scr.mlx);
	return (0);
}

static void	setting(void)
{
	t_camera	*c;
	t_minirt	*g;

	g = m();
	g->scr.win = mlx_new_window(\
		g->scr.mlx, g->scr.wid, g->scr.hei, "this is minirt");
	g->scr.anti = ANTI_ALIASING;
	g->scr.mouse_x = -1;
	g->scr.mouse_y = -1;
	c = g->cam;
	while (c->next)
		c = c->next;
	c->next = g->cam->next;
	g->curr_cam = g->cam->next;
	g->gui_toggle = 1;
	g->light_toggle = 1;
	g->resolution_toggle = 1;
	g->texture_toggle = 1;
	g->ray_mode = 1;
	mlx_hook(g->scr.win, 2, 0, key_down, 0);
	mlx_hook(g->scr.win, 3, 0, key_up, 0);
	mlx_hook(g->scr.win, 17, 0, exit_hook, 0);
	mlx_hook(g->scr.win, 4, 0, mouse_down, 0);
	mlx_hook(g->scr.win, 5, 0, mouse_up, 0);
	mlx_hook(g->scr.win, 6, 0, mouse_move, 0);
}

static int	init(void)
{
	t_minirt	*g;

	g = m();
	ft_memset(m(), 0, sizeof(t_minirt));
	g->wrd = init_world();
	g->cam = init_camera();
	g->light = init_light();
	if (!g->wrd || !g->cam || !g->light)
		return (ERROR);
	g->scr.mlx = mlx_init();
	mlx_loop_hook(g->scr.mlx, loop_hook, 0);
	return (OK);
}

t_minirt	*m(void)
{
	static t_minirt	mini;

	return (&mini);
}

int	main(int argc, char **argv)
{
	void	*back;

	if (!init() || !input(argc, argv))
	{
		printf("Error\n");
		return (ERROR);
	}
	setting();
	ft_memset(m()->keys, 0, sizeof(m()->keys));
	back = mlx_new_image(m()->scr.mlx, m()->scr.wid, m()->scr.hei);
	mlx_put_image_to_window(m()->scr.mlx, m()->scr.win, back, 0, 0);
	render();
	set_gui(m()->curr_cam);
	mlx_loop(m()->scr.mlx);
	return (0);
}
