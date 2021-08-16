/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_zombie_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:17:09 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:17:12 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

void	scr_zombie_move(t_instance *this)
{
	t_instance	*ins;

	if (this->condition & C_DEING)
	{
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_blue_die_right_reverse);
		else
			change_sprite(this, g()->asset.spr_zombie_blue_die_left_reverse);
		if (this->img_node->next == 0)
			this->condition = C_ALIVE;
	}
	else if (this->condition & C_ALIVE)
	{
		ins = g()->global.player;
		if (ins && point_distance(this->x, this->y, ins->x, ins->y) < 100 * 100)
		{
			this->dir = 0;
			if (ins->x > this->x)
				this->dir = 1;
		}
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_blue_idle_right_reverse);
		else
			change_sprite(this, g()->asset.spr_zombie_blue_idle_left_reverse);
	}
}
