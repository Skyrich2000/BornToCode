/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:53 by ycha              #+#    #+#             */
/*   Updated: 2021/08/06 04:58:52 by ycha             ###   ########.fr       */
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
	t_instance *ins;

	ins = create_instance(scr_player_get_spr(SPR_IDLE, g()->global.inverted, 1), (int [3]){PLAYER, x, y}, obj_player_step, obj_player_draw);
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

void		obj_player_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_player_step start\n");

	if (this->signal & SIG_MV_AUTO)
	{
		scr_player_move_auto(this);
		scr_player_collision_trigger(this);
		scr_player_collision_inverter(this);
		if (!(this->signal & 0b11110))
			scr_player_check_selfs(this);
		scr_save_footprint(this, this->obj.player.route);
	}
	else if (!(this->condition & C_AVATAR))
	{
		if (this->condition & C_ALIVE)
		{
			scr_player_move(this);
			scr_player_attack(this);
			scr_player_collision_gold(this);
			scr_player_collision_wait(this);
			scr_player_collision_trigger(this);
			scr_player_collision_inverter(this);
			scr_player_collision_exit(this);
			scr_player_check_selfs(this);
			scr_save_footprint(this, this->obj.player.route);
		}
		else if (this->condition & C_DEING)
		{
			change_sprite(this, scr_player_get_spr(SPR_DIE, this->obj.player.inverted, this->dir));
			if (this->img_node->next == 0)
				this->condition = C_DEAD;
		}
	}
	else
	{
		if (this->obj.player.inverted == S_STRAIGHT)
		{
			if (g()->global.time > 0)
				scr_load_footprint(this, &this->obj.player.route_node, this->obj.player.inverted);
		}
		else
			scr_load_footprint(this, &this->obj.player.route_node, this->obj.player.inverted);
	}

	if (this->condition & C_ALIVE)
		scr_player_collision_zombie(this);

	if (DEBUG)
		printf("obj_player_step end\n");
}

void		obj_player_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_player_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);

	if (!(this->condition & C_AVATAR))
		if (!(this->condition & C_DEAD))
			scr_animation(this);

	if (DEBUG) printf("obj_player_draw end\n");
}
