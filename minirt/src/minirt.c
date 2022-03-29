/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:24:28 by ycha              #+#    #+#             */
/*   Updated: 2021/06/15 14:25:49 by ycha             ###   ########.fr       */
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

	m()->scr.win = mlx_new_window(
		m()->scr.mlx, m()->scr.wid, m()->scr.hei, "this is minirt");
	m()->scr.anti = ANTI_ALIASING;
	m()->scr.mouse_x = -1;
	m()->scr.mouse_y = -1;
	c = m()->cam;
	while (c->next)
		c = c->next;
	c->next = m()->cam->next;
	m()->curr_cam = m()->cam->next;
	m()->gui_toggle = 1;
	m()->light_toggle = 1;
	m()->resolution_toggle = 1;
	m()->ray_mode = 1;
	ft_memset(m()->keys, 0, sizeof(m()->keys));
	mlx_hook(m()->scr.win, 2, 0, key_down, 0);
	mlx_hook(m()->scr.win, 3, 0, key_up, 0);
	mlx_hook(m()->scr.win, 17, 0, exit_hook, 0);
	mlx_hook(m()->scr.win, 4, 0, mouse_down, 0);
	mlx_hook(m()->scr.win, 5, 0, mouse_up, 0);
	mlx_hook(m()->scr.win, 6, 0, mouse_move, 0);
	mlx_loop_hook(m()->scr.mlx, loop_hook, 0);
}

static int	init(void)
{
	ft_memset(m(), 0, sizeof(t_minirt));
	m()->wrd = init_world();
	m()->cam = init_camera();
	m()->light = init_light();
	if (!m()->wrd || !m()->cam || !m()->light)
		return (ERROR);
	m()->scr.mlx = mlx_init();
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
	back = mlx_new_image(m()->scr.mlx, m()->scr.wid, m()->scr.hei);
	mlx_put_image_to_window(m()->scr.mlx, m()->scr.win, back, 0, 0);
	render();
	set_gui(m()->curr_cam);
	mlx_loop(m()->scr.mlx);
	return (0);
}
