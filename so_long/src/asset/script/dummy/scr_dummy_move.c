/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_dummy_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:14:37 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:15:16 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define SPR_MOVE			1
#define SPR_MOVE_REVERSE	2

void	scr_dummy_move_auto(t_instance *this)
{
	int	type;
	int	dir;

	this->obj.dummy.time++;
	if (this->obj.dummy.alive_time != -1 && \
							this->obj.dummy.time > this->obj.dummy.alive_time)
		destroy_instance(this);
	this->x += (((this->signal & SIG_MV_RIGHT) > 0) - ((this->signal & SIG_MV_LEFT) > 0)) * 2;
	this->y += (((this->signal & SIG_MV_DOWN) > 0) - ((this->signal & SIG_MV_UP) > 0)) * 2;
	type = SPR_MOVE;
	dir = ((this->signal & SIG_DIR_RIGHT) > 0) - ((this->signal & SIG_DIR_LEFT) > 0);
	if (this->obj.dummy.inverted == S_INVERT)
		type = SPR_MOVE_REVERSE;
	change_sprite(this, scr_player_get_spr(type, this->obj.dummy.inverted, dir));
}
