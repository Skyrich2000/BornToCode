/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_inverter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:10:13 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:10:15 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

t_instance	*create_inverter_instance(int x, int y, \
												int inverted, int out_dir[20])
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_inverter_idle, \
			(int [3]){INVERTER, x, y}, obj_inverter_step, obj_inverter_draw);
	ins->obj.inverter.time = 0;
	ins->obj.inverter.inverted = inverted;
	ins->obj.inverter.dummy = 0;
	sl_bzero(ins->obj.inverter.out_dir, sizeof(ins->obj.inverter.out_dir));
	sl_bzero(ins->obj.inverter.triggers, sizeof(ins->obj.inverter.triggers));
	sl_bzero(ins->obj.inverter.waits, sizeof(ins->obj.inverter.waits));
	ins->obj.inverter.out_dir[SIG_MV_LEFT] = out_dir[SIG_MV_LEFT];
	ins->obj.inverter.out_dir[SIG_MV_RIGHT] = out_dir[SIG_MV_RIGHT];
	ins->obj.inverter.out_dir[SIG_MV_UP] = out_dir[SIG_MV_UP];
	ins->obj.inverter.out_dir[SIG_MV_DOWN] = out_dir[SIG_MV_DOWN];
	ins->condition = C_ALIVE;
	create_wall_inv_instance(ins->x, ins->y);
	if (inverted == S_STRAIGHT)
		scr_inverter_start(ins);
	else
		scr_inverter_create_wait(ins);
	return (ins);
}

void	obj_inverter_step(t_instance *this)
{
	DEBUG && printf("obj_inverter_step start\n");
	if (g()->global.state == S_GAMEOVER)
	{
		g()->frame.skip_frame = 0;
		g()->global.darkness = 0;
		return ;
	}
	scr_inverter_change_sprite(this);
	if (this->obj.inverter.inverted == S_INVERT && \
		g()->global.inverted == S_INVERT && \
		g()->global.time == 0)
		scr_inverter_start(this);
	if (this->obj.inverter.inverted == g()->global.inverted)
	{
		if (this->signal & SIG_BEFORE)
			scr_inverter_before(this);
		else if (this->signal & SIG_ACTIVE)
			scr_inverter_active(this);
		this->signal = 0;
	}
	scr_inverter_skip_frame(this);
	DEBUG && printf("obj_inverter_step end\n");
}

void	obj_inverter_draw(t_instance *this)
{
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	scr_animation(this);
}
