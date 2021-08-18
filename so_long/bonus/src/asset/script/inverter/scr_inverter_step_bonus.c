/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_inverter_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:19:34 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:23:01 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

void	scr_inverter_skip_frame(t_instance *this)
{
	if (this->obj.inverter.dummy)
	{
		g()->frame.skip_frame = this->obj.inverter.time / 4;
		g()->global.darkness = this->obj.inverter.time / 3;
		this->obj.inverter.time++;
	}
	else if (this->obj.inverter.time)
	{
		g()->frame.skip_frame = this->obj.inverter.time / 4;
		g()->global.darkness = this->obj.inverter.time / 3;
		this->obj.inverter.time--;
	}
}

void	scr_inverter_change_sprite(t_instance *this)
{
	t_sprite	*spr;

	if (g()->global.inverted == this->obj.inverter.inverted)
	{
		spr = g()->asset.spr_inverter_red;
		if (this->obj.inverter.inverted)
			spr = g()->asset.spr_inverter_blue;
		change_sprite(this, spr);
	}
	else
		change_sprite(this, g()->asset.spr_inverter_idle);
}

void	scr_inverter_start(t_instance *this)
{
	scr_inverter_destroy_wait(this);
	scr_inverter_create_trigger(this);
}
