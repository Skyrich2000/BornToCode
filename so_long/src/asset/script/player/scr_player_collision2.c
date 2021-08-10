/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_collision2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:35:52 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:42:46 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

void	scr_player_collision_trigger(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, TRIGGER);
	if (ins && \
		this->obj.player.inverted == ins->obj.trigger.inverted)
		scr_trigger(ins);
}

void	scr_player_collision_zombie(t_instance *this)
{
	t_instance	*zombie;

	zombie = place_meeting_type(this, this->x, this->y, ZOMBIE_BLUE);
	if (zombie)
	{
		if (zombie->condition & C_ALIVE)
		{
			if (zombie == this->obj.player.reviving_zombie)
				return ;
			else
			{
				if (this->obj.player.inverted == 1 && \
					g()->global.state == S_RESTRAIGHT && \
					this == zombie->obj.zombie.reviver)
					return ;
				g()->global.view_xview_aim = this->x - g()->view.view_wview / 2;
				g()->global.view_yview_aim = this->y - g()->view.view_hview / 2;
				scr_player_die(TXT_HIT_BY_ZOMBIE);
			}
		}
	}
	else
		this->obj.player.reviving_zombie = 0;
}
