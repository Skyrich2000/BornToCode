/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:20:48 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:20:49 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(void)
{
	exit(0);
}

static void	key_for_rerender(int keycode)
{
	t_minirt	*g;

	g = m();
	if (keycode == KEY_R)
	{
		g->resolution_toggle = !g->resolution_toggle;
		g->scr.lower_resolution = LOWER_RESOLUTION * !g->resolution_toggle;
	}
	if (keycode == KEY_C)
		g->curr_cam = g->curr_cam->next;
	else if (keycode == KEY_PLUS)
		g->scr.anti += 5;
	else if (keycode == KEY_MINUS)
		g->scr.anti = ft_max(0, g->scr.anti - 5);
	else if (keycode == KEY_L)
		g->light_toggle = !g->light_toggle;
	else if (keycode == KEY_M)
		g->ray_mode = !g->ray_mode;
	else if (keycode == KEY_T)
		g->texture_toggle = !g->texture_toggle;
}

int	key_up(int keycode)
{
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_G)
	{
		m()->gui_toggle = !m()->gui_toggle;
		return (0);
	}
	if (keycode == KEY_P)
	{
		key_save();
		return (0);
	}
	key_for_rerender(keycode);
	m()->keys[keycode] = 0;
	m()->render_refresh = 1;
	return (0);
}

int	key_down(int keycode)
{
	m()->keys[keycode] = 1;
	return (0);
}
