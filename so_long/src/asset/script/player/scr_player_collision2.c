/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_collision2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:25:14 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:25:15 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

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
				scr_player_die(TXT_HIT_BY_ZOMBIE, this);
			}
		}
	}
	else
		this->obj.player.reviving_zombie = 0;
}
