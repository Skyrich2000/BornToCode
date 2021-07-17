/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:56 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 03:11:42 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

t_instance	*create_zombie_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_zombie_idle_right, (int [3]){ZOMBIE, x, y}, 0, obj_zombie_draw);
	if (!ins)
		return (ERROR);
	ins->obj.zombie.hp = 100;
	return (ins);
}

void        obj_zombie_draw(t_instance *this)
{
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	this->draw_time++;
	if (this->draw_time > this->img_speed)
	{
		this->img_node = this->img_node->next;
		this->draw_time = 0;
	}
	if (!this->img_node)
		this->img_node = this->spr->imgs->next;
}
