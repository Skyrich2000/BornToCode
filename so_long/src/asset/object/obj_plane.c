/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:24:46 by su                #+#    #+#             */
/*   Updated: 2021/08/10 17:32:30 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance	*create_plane_instance(void)
{
	int			x;
	int			y;
	t_instance	*ins;

	x = g()->global.player->x;
	y = 500;
	ins = create_instance(g()->asset.spr_plane, \
						(int [3]){PLANE, x, y}, obj_plane_step, draw_self);
	return (ins);
}

void	obj_plane_step(t_instance *this)
{
	if (g()->global.player && g()->global.player->y - 10 > this->y)
	{
		if (g()->global.invert_signal == SIG_NO_INVERT)
			g()->global.state = S_CLEAR;
		destroy_instance(g()->global.player);
		g()->global.player = 0;
	}
	this->y -= 5;
	if (this->y < g()->view.view_yview - 42)
		destroy_instance(this);
}
