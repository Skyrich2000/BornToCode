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
	int				i;
	const t_camera	*cam = m()->curr_cam;

	if (cam->img)
		mlx_put_image_to_window(\
					m()->scr.mlx, \
					m()->scr.win, \
					cam->img, 0, 0);
	i = -1;
	while (++i < cam->gui_object_top)
	{
		mlx_string_put(m()->scr.mlx, m()->scr.win, \
					cam->gui_object[i].pos.x, cam->gui_object[i].pos.y, \
					0xFFFFFF, "SP 1");
	}
	mlx_do_sync(m()->scr.mlx);
	return (0);
}

static void	setting(void)
{
	t_camera	*c;

	m()->scr.mlx = mlx_init();
	m()->scr.win = mlx_new_window(
		m()->scr.mlx, m()->scr.wid, m()->scr.hei, "this is minirt");
	m()->scr.anti = ANTI_ALIASING;
	c = m()->cam;
	while (c->next)
		c = c->next;
	c->next = m()->cam->next;
	m()->curr_cam = m()->cam->next;
	m()->light_toggle = 1;
	mlx_key_hook(m()->scr.win, key_hook, 0);
	mlx_hook(m()->scr.win, 17, 0, exit_hook, 0);
	mlx_hook(m()->scr.win, 4, 0, mouse_down, 0);
	mlx_hook(m()->scr.win, 5, 0, mouse_up, 0);
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
	draw();
	back = mlx_new_image(m()->scr.mlx, m()->scr.wid, m()->scr.hei);
	mlx_put_image_to_window(m()->scr.mlx, m()->scr.win, back, 0, 0);
	mlx_loop(m()->scr.mlx);
	return (0);
}
