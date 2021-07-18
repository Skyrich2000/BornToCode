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

	ins = create_instance(g()->asset.spr_zombie_idle_right, (int [3]){ZOMBIE, x, y}, obj_zombie_step, obj_zombie_draw);
	if (!ins)
		return (ERROR);
	ins->obj.zombie.die = 0;
	return (ins);
}

void		obj_zombie_step(t_instance *this)
{

	t_instance *ins;

	ins = g()->instances[PLAYER]->next->data;
	if (this->obj.zombie.die == 0 && point_distance(this->x, this->y, ins->x, ins->y) < 25 * 25)
	{
		this->dir = -1;
		if (ins->x > this->x)
			this->dir = 1;
	}
	if (this->obj.zombie.die)
	{
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_die_right);
		else
			change_sprite(this, g()->asset.spr_zombie_die_left);

	}
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
	{
		if (this->obj.zombie.die)
		{
			change_sprite(this, g()->asset.spr_empty);
		}
		this->img_node = this->spr->imgs->next;
	}
}
