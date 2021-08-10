/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_gold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:23:17 by su                #+#    #+#             */
/*   Updated: 2021/08/10 17:32:20 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance	*create_gold_red_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_gold_red, \
			(int [3]){GOLD_RED, x, y}, obj_gold_red_step, obj_gold_red_draw);
	ins->obj.gold.route = create_list();
	ins->obj.gold.route_node = 0;
	ins->condition = C_ALIVE;
	g()->global.gold_num++;
	return (ins);
}

void	obj_gold_red_step(t_instance *this)
{
	if (!(this->condition & C_AVATAR))
	{
		if (this->condition & C_DEING)
		{
			change_sprite(this, g()->asset.spr_gold_red_break);
			if (this->img_node->next == 0)
				this->condition = C_DEAD;
		}
		else if (this->condition & C_DEAD)
			change_sprite(this, g()->asset.spr_empty);
		if (g()->global.state == S_STRAIGHT)
			scr_save_footprint(this, this->obj.gold.route);
	}
	else if (g()->global.state != S_GAMEOVER)
	{
		if (g()->global.time > 0)
			scr_load_footprint(this, &this->obj.gold.route, 0);
	}
}

void	obj_gold_red_draw(t_instance *this)
{
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	if (!(this->condition & C_AVATAR))
		scr_animation(this);
}
