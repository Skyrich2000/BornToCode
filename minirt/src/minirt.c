/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:24:28 by ycha              #+#    #+#             */
/*   Updated: 2022/04/25 19:44:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	setting(void)
{
	t_camera	*c;
	t_minirt	*g;

	g = m();
	g->scr.win = mlx_new_window(\
		g->scr.mlx, g->scr.wid, g->scr.hei, "this is minirt");
	c = m()->cam;
	while (c->next)
		c = c->next;
	c->next = m()->cam->next;
	m()->curr_cam = m()->cam->next;
	mlx_key_hook(m()->scr.win, key_hook, 0);
	mlx_hook(m()->scr.win, 17, 0, exit_hook, 0);
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
	m()->scr.wid = 800;
	m()->scr.hei = 600;
	return (OK);
}

int	loop_hook(void)
{
	if (m()->curr_cam->img)
		mlx_put_image_to_window(\
					m()->scr.mlx, \
					m()->scr.win, \
					m()->curr_cam->img, 0, 0);
	mlx_do_sync(m()->scr.mlx);
	return (0);
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
	m()->scr.wid = 800;
	m()->scr.hei = 600;
	setting();
	draw();
	mlx_loop_hook(m()->scr.mlx, loop_hook, 0);
	back = mlx_new_image(m()->scr.mlx, m()->scr.wid, m()->scr.hei);
	mlx_put_image_to_window(m()->scr.mlx, m()->scr.win, back, 0, 0);
	mlx_loop(m()->scr.mlx);
	return (0);
}
