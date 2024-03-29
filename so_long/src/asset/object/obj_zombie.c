/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_zombie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:12:56 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:12:58 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

t_instance	*create_zombie_blue_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_zombie_blue_die_right_reverse, \
							(int [3]){ZOMBIE_BLUE, x, y}, \
							obj_zombie_blue_step, \
							obj_zombie_blue_draw);
	ins->obj.zombie.route = create_list();
	ins->obj.zombie.route_node = 0;
	ins->obj.zombie.reviver = 0;
	ins->condition = C_DEAD;
	return (ins);
}

void	obj_zombie_blue_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_zombie_step start\n");
	if (!(this->condition & C_AVATAR))
	{
		scr_zombie_move(this);
		if (g()->global.state == S_INVERT)
			scr_save_footprint(this, this->obj.zombie.route);
	}
	else if (g()->global.state != S_GAMEOVER)
		scr_load_footprint(this, &this->obj.zombie.route_node, 1);
	if (DEBUG)
		printf("obj_zombie_step end\n");
}

void	obj_zombie_blue_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_zombie_draw start\n");
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	if (!(this->condition & C_AVATAR || this->condition & C_DEAD))
		scr_animation(this);
	if (DEBUG)
		printf("obj_zombie_draw end\n");
}
