/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:20:44 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:20:45 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define GUI_CLICK_SIZE 10

static void	click_obj(int x, int y)
{
	int			i;
	t_camera	*cam;

	i = -1;
	cam = m()->curr_cam;
	while (++i < cam->gui_object_top)
	{
		if (x >= cam->gui_object[i].pos.x - GUI_CLICK_SIZE && \
			x <= cam->gui_object[i].pos.x + GUI_CLICK_SIZE && \
			y >= cam->gui_object[i].pos.y - GUI_CLICK_SIZE && \
			y <= cam->gui_object[i].pos.y + GUI_CLICK_SIZE)
		{
			cam->select_gui_object = cam->gui_object[i];
			return ;
		}
	}
	cam->select_gui_object.obj = 0;
}

int	mouse_down(int button, int x, int y, void *param)
{
	t_minirt	*g;

	(void)param;
	g = m();
	click_obj(x, y);
	g->scr.mouse_button = button;
	g->scr.mouse_x = x;
	g->scr.mouse_y = y;
	g->scr.cam_start_pos = g->curr_cam->pos;
	g->scr.cam_start_dir = g->curr_cam->dir;
	if (g->curr_cam->select_gui_object.obj)
	{
		g->scr.obj_start_pos = *get_object_pos(\
									g->curr_cam->select_gui_object.obj, \
									g->curr_cam->select_gui_object.type);
		g->scr.obj_start_dir = get_object_dir(\
									g->curr_cam->select_gui_object.obj, \
									g->curr_cam->select_gui_object.type);
	}
	return (0);
}
