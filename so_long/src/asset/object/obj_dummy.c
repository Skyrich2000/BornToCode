/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_dummy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:56 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 02:55:17 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance	*create_dummy_instance(int x, int y, int inverted, int time)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_player_blue_move_right, (int [3]){DUMMY, x, y}, obj_dummy_step, obj_dummy_draw);
	ins->obj.dummy.inverted = inverted;
	ins->obj.dummy.time = 0;
	ins->obj.dummy.alive_time = time;
	return (ins);
}

void		obj_dummy_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_dummy_step start\n");

	if (this->signal & SIG_MV_AUTO)
		scr_dummy_move_auto(this);

	if (DEBUG)
		printf("obj_dummy_step end\n");
}

void	obj_dummy_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_dummy_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);
	scr_animation(this);

	if (DEBUG)
		printf("obj_dummy_draw end\n");
}
