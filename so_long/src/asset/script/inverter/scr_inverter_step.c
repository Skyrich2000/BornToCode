/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_inverter_step.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:36:14 by su                #+#    #+#             */
/*   Updated: 2021/08/10 19:41:14 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
