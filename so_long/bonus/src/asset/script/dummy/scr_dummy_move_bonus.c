/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_dummy_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:19:13 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:19:15 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

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
	this->x += (((this->signal & SIG_MV_RIGHT) > 0) - \
				((this->signal & SIG_MV_LEFT) > 0)) * 2;
	this->y += (((this->signal & SIG_MV_DOWN) > 0) - \
				((this->signal & SIG_MV_UP) > 0)) * 2;
	type = SPR_MOVE;
	dir = ((this->signal & SIG_DIR_RIGHT) > 0) - \
			((this->signal & SIG_DIR_LEFT) > 0);
	if (this->obj.dummy.inverted == S_INVERT)
		type = SPR_MOVE_REVERSE;
	change_sprite(this, scr_player_get_spr(type, \
											this->obj.dummy.inverted, dir));
}
