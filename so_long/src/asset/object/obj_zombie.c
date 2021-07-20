/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_zombie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:56 by ycha              #+#    #+#             */
/*   Updated: 2021/07/21 04:03:21 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

t_instance	*create_zombie_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_zombie_die_right_reverse, (int [3]){ZOMBIE, x, y}, obj_zombie_step, obj_zombie_draw);
	if (!ins)
		return (ERROR);
	ins->obj.zombie.status = 0;
	ins->obj.zombie.route = create_list();
	return (ins);
}

static void z_footprint(t_instance *this)
{
	t_footprint	*footprint;

	footprint = malloc(sizeof(t_footprint));
	footprint->x = this->x;
	footprint->y = this->y;
	footprint->spr = this->spr;
	footprint->img_node = this->img_node;
	push_list(this->obj.zombie.route, footprint);
}

/*
** 0 : dead body
** 1 : dead reverse animation
** 2 : alive
*/
void		obj_zombie_step(t_instance *this)
{
	t_instance *ins;

	if (DEBUG)
		printf("obj_zombie_step start\n");
	if (this->obj.zombie.status == 1) // dead reverse animation
	{
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_die_right_reverse);
		else
			change_sprite(this, g()->asset.spr_zombie_die_left_reverse);
		if (this->img_node->next == 0) // if dead reverse animation done
			this->obj.zombie.status = 2;
	}
	else if (this->obj.zombie.status == 2) // alive
	{
		ins = g()->instances[PLAYER]->next->data;
		if (point_distance(this->x, this->y, ins->x, ins->y) < 50 * 50)
		{
			this->dir = 0;
			if (ins->x > this->x)
				this->dir = 1;
		}
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_idle_right_reverse);
		else
			change_sprite(this, g()->asset.spr_zombie_idle_left_reverse);
	}
	if (g()->global.status == 1)
		z_footprint(this);
	if (DEBUG)
		printf("obj_zombie_step end\n");
}

void        obj_zombie_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_zombie_draw start\n");
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	if (this->obj.zombie.status != 0)
	{
		this->draw_time++;
		if (this->draw_time > this->spr->img_speed)
		{
			this->img_node = this->img_node->next;
			this->draw_time = 0;
		}
		if (!this->img_node)
			this->img_node = this->spr->imgs->next;
	}
	if (DEBUG)
		printf("obj_zombie_draw end\n");
}
