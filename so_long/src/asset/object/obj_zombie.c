/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_zombie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:56 by ycha              #+#    #+#             */
/*   Updated: 2021/07/22 04:17:25 by ycha             ###   ########.fr       */
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
	ins->obj.zombie.route = create_list();
	ins->obj.zombie.route_node = 0;
	ins->condition = C_DEAD;
	return (ins);
}

static void	z_move(t_instance *this)
{
	t_instance *ins;

	//0010
	if (this->condition & C_DEING)
	{
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_die_right_reverse);
		else
			change_sprite(this, g()->asset.spr_zombie_die_left_reverse);
		if (this->img_node->next == 0)
			this->condition = C_ALIVE;
	}
	else if (this->condition & C_ALIVE)
	{
		ins = g()->instances[PLAYER]->next->data;
		if (ins && point_distance(this->x, this->y, ins->x, ins->y) < 50 * 50)
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
}

void		obj_zombie_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_zombie_step start\n");

	if (!(this->condition & C_AVATAR))
	{
		z_move(this);
		if (g()->global.state == S_INVERT)
			scr_save_footprint(this, this->obj.zombie.route);
	}
	else
		scr_load_footprint(this, &this->obj.zombie.route_node, 1);

	if (DEBUG)
		printf("obj_zombie_step end\n");
}

void	obj_zombie_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_zombie_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);
	if (!(this->condition & C_AVATAR || this->condition & C_DEAD))
		scr_animation(this);

	if (DEBUG)
		printf("obj_zombie_draw end\n");
}
