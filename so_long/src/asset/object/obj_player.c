/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:53 by ycha              #+#    #+#             */
/*   Updated: 2021/08/10 19:37:15 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

#define	SPR_IDLE	0
#define	SPR_MOVE	1
#define	SPR_ATTACK	3
#define SPR_DIE		4

t_instance	*create_player_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(scr_player_get_spr(SPR_IDLE, \
												g()->global.inverted, 1), \
												(int [3]){PLAYER, x, y}, \
												obj_player_step, \
												obj_player_draw);
	ins->obj.player.inverted = g()->global.inverted;
	ins->obj.player.attack = 0;
	ins->obj.player.route = create_list();
	ins->obj.player.route_node = 0;
	ins->obj.player.reviving_zombie = 0;
	ins->dir = 1;
	ins->condition = C_ALIVE;
	g()->global.player = ins;
	return (ins);
}

void	obj_player_step(t_instance *this)
{
	DEBUG && printf("obj_player_step start\n");
	if (this->signal & SIG_MV_AUTO)
		scr_player_step_signal(this);
	else if (!(this->condition & C_AVATAR))
		scr_player_step_normal(this);
	else
		scr_player_step_avatar(this);
	if (this->condition & C_ALIVE)
		scr_player_collision_zombie(this);
	DEBUG && printf("obj_player_step end\n");
}

void	obj_player_draw(t_instance *this)
{
	DEBUG && printf("obj_player_draw start\n");
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	if (!(this->condition & C_AVATAR))
		if (!(this->condition & C_DEAD))
			scr_animation(this);
	DEBUG && printf("obj_player_draw end\n");
}
