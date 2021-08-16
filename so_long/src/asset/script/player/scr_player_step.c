/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_step.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:25:52 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:25:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

#define	SPR_MOVE	1
#define	SPR_ATTACK	3
#define SPR_DIE		4

void	scr_player_step_signal(t_instance *this)
{
	scr_player_move_auto(this);
	scr_player_collision_trigger(this);
	scr_player_collision_inverter(this);
	if (!(this->signal & 0b11110))
		scr_player_check_selfs(this);
	scr_save_footprint(this, this->obj.player.route);
}

void	scr_player_step_normal(t_instance *this)
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
		change_sprite(this, scr_player_get_spr(SPR_DIE, \
								this->obj.player.inverted, this->dir));
		if (this->img_node->next == 0)
			this->condition = C_DEAD;
	}
}

void	scr_player_step_avatar(t_instance *this)
{
	if (this->obj.player.inverted == S_STRAIGHT)
	{
		if (g()->global.time > 0)
			scr_load_footprint(this, \
				&this->obj.player.route_node, this->obj.player.inverted);
	}
	else
		scr_load_footprint(this, \
			&this->obj.player.route_node, this->obj.player.inverted);
}
