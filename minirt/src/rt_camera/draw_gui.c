/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:52:51 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:52:51 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*get_object_name(int type)
{
	if (type == LIGHT)
		return ("L");
	return ("O");
}

static void	draw_help(void)
{
	void		*mlx;
	void		*win;
	const int	h = m()->scr.hei;
	char		*text;

	mlx = m()->scr.mlx;
	win = m()->scr.win;
	text = ft_itoa(m()->scr.anti);
	mlx_string_put(mlx, win, 10, 20 + 15 * 0, 0x0, "R - toggle resolution");
	mlx_string_put(mlx, win, 10, 20 + 15 * 1, 0x0, "L - toggle light");
	mlx_string_put(mlx, win, 10, 20 + 15 * 2, 0x0, "M - toggle ray mode");
	mlx_string_put(mlx, win, 10, 20 + 15 * 3, 0x0, "T - toggle texture");
	mlx_string_put(mlx, win, 10, 20 + 15 * 4, 0x0, "G - toggle gui");
	mlx_string_put(mlx, win, 10, 20 + 15 * 5, 0x0, "C - next camera");
	mlx_string_put(mlx, win, 10, 20 + 15 * 6, 0x0, "+- - anti-aliasing : ");
	mlx_string_put(mlx, win, 160, 20 + 15 * 6, 0x0, text);
	mlx_string_put(mlx, win, 10, h - 90, 0x0, "Left Mouse - camera direction");
	mlx_string_put(mlx, win, 10, h - 75, 0x0, "Left Mouse - move object");
	mlx_string_put(mlx, win, 10, h - 60, 0x0, "Right Mouse - change object");
	mlx_string_put(mlx, win, 10, h - 45, 0x0, "WASD - move camera");
	mlx_string_put(mlx, win, 10, h - 30, 0x0, "Shift - camera down");
	mlx_string_put(mlx, win, 10, h - 15, 0x0, "Space - camera up");
	free(text);
}

void	draw_gui(void)
{
	static int		loop_color = 0;
	int				i;
	const t_camera	*cam = m()->curr_cam;

	loop_color += 0x112233;
	draw_help();
	if (cam->select_gui_object.obj)
	{
		mlx_string_put(m()->scr.mlx, m()->scr.win, \
					cam->select_gui_object.pos.x, cam->select_gui_object.pos.y, \
					loop_color, get_object_name(cam->select_gui_object.type));
		return ;
	}
	i = -1;
	while (++i < cam->gui_object_top)
	{
		mlx_string_put(m()->scr.mlx, m()->scr.win, \
					cam->gui_object[i].pos.x, cam->gui_object[i].pos.y, \
					0x0, get_object_name(cam->gui_object[i].type));
	}
	return ;
}
