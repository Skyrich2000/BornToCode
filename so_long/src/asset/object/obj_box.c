/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:09:43 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance	*create_box_red_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_box_red, (int [3]){BOX_RED, x, y}, \
											obj_box_red_step, obj_box_red_draw);
	ins->obj.box.route = create_list();
	ins->obj.box.route_node = 0;
	ins->condition = C_ALIVE;
	return (ins);
}

t_instance	*create_box_blue_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_box_blue, (int [3]){BOX_BLUE, x, y}, \
																0, draw_self);
	create_wall_inv_instance(x, y);
	create_wall_inv_instance(x, y - 8);
	return (ins);
}

void	obj_box_red_step(t_instance *this)
{
	if (!(this->condition & C_AVATAR))
	{
		if (this->condition & C_DEING)
		{
			change_sprite(this, g()->asset.spr_box_red_break);
			if (this->img_node->next == 0)
				this->condition = C_DEAD;
		}
		else if (this->condition & C_DEAD)
			change_sprite(this, g()->asset.spr_empty);
		if (g()->global.state == S_STRAIGHT)
			scr_save_footprint(this, this->obj.box.route);
	}
	else if (g()->global.state != S_GAMEOVER)
	{
		if (g()->global.time > 0)
			scr_load_footprint(this, &this->obj.box.route, 0);
	}
}

void	obj_box_red_draw(t_instance *this)
{
	draw_self(this);
	if (!(this->condition & C_AVATAR))
		scr_animation(this);
}
