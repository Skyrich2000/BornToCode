/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:25:32 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:25:32 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	move_object(t_camera *cam, t_vec diff)
{
	t_minirt		*g;
	t_gui_object	*gui;
	t_vec			*pos;

	g = m();
	if (cam->select_gui_object.obj && g->scr.mouse_button != 2)
	{
		gui = &cam->select_gui_object;
		g->scr.obj_start_pos = vec_add(g->scr.obj_start_pos, diff);
		pos = get_object_pos(gui->obj, gui->type);
		set_object_pos(gui->obj, gui->type, vec_add(*pos, diff));
	}
}

void	key_camera_move(void)
{
	t_vec			diff;
	t_camera		*cam;

	cam = m()->curr_cam;
	if (m()->keys[KEY_W])
		diff = vec_unit_(&cam->dir);
	if (m()->keys[KEY_S])
		diff = vec_oppo(vec_unit_(&cam->dir));
	if (m()->keys[KEY_D])
		diff = vec_unit_(&cam->hor);
	if (m()->keys[KEY_A])
		diff = vec_oppo(vec_unit_(&cam->hor));
	if (m()->keys[KEY_SPACEBAR])
		diff = vec_unit_(&cam->ver);
	if (m()->keys[KEY_LEFT_SHIFT])
		diff = vec_oppo(vec_unit_(&cam->ver));
	if (m()->keys[KEY_W] || m()->keys[KEY_S] || m()->keys[KEY_D] || \
		m()->keys[KEY_A] || m()->keys[KEY_SPACEBAR] || \
		m()->keys[KEY_LEFT_SHIFT])
	{
		set_camera(cam, vec_add(cam->pos, diff), cam->dir, cam->fov);
		move_object(cam, diff);
		m()->render_refresh += 1;
	}
}
