/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_collision1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:35:52 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:42:54 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

int	scr_player_collision_box(t_instance *this)
{
	t_instance	*wall;
	t_instance	*box;
	t_instance	*wall_inv;

	wall = place_meeting_type(this, this->x, this->y, WALL);
	box = place_meeting_type(this, this->x, this->y, BOX_RED);
	wall_inv = place_meeting_type(this, this->x, this->y, WALL_INV);
	return (wall || wall_inv || (box && box->condition & C_ALIVE));
}

void	scr_player_collision_wait(t_instance *this)
{
	if (place_meeting_type(this, this->x, this->y, WAIT))
		g()->global.text = TXT_WAIT;
	else
		g()->global.text = 0;
}

void	scr_player_collision_gold(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, GOLD_RED);
	if (ins && ins->condition & C_ALIVE && \
		g()->global.state == S_STRAIGHT)
	{
		ins->condition = C_DEING;
		--g()->global.gold_num;
	}
}

void	scr_player_collision_exit(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, EXIT);
	if (ins && ins->condition & C_ALIVE && \
		(g()->global.state == S_RESTRAIGHT || g()->global.invert_signal == SIG_NO_INVERT) && \
		g()->global.gold_num == 0)
	{
		create_plane_instance();
		this->signal = SIG_MV_AUTO;
		ins->condition = C_DEAD;
	}
}

void	scr_player_collision_inverter(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, INVERTER);
	if (ins && ins->condition & C_ALIVE && \
		ins->obj.inverter.inverted == this->obj.player.inverted)
	{
		ins->condition = C_DEING;
		ins->signal = SIG_ACTIVE | this->signal;
	}
}
