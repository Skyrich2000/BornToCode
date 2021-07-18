/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:53 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 04:25:15 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

t_instance	*create_player_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_player_idle_right, (int [3]){PLAYER, x, y}, obj_player_step, obj_player_draw);
	if (!ins)
		return (ERROR);
	ins->obj.player.hp = 0;
	ins->obj.player.attack = 0;
	ins->obj.player.h_mv = 0;
	ins->obj.player.v_mv = 0;
	ins->obj.player.prev_x = x;
	ins->obj.player.prev_y = y;
	ins->dir = 1;
	return (ins);
}

void		obj_player_step(t_instance *this)
{
	int h_mv;
	int v_mv;
	t_footprint *footprint;
	t_instance	*ins;

	this->obj.player.prev_x = this->x;
	this->obj.player.prev_y = this->y;
	if (keyboard_check(KEY_D) || keyboard_check(KEY_RIGHT))
		this->dir = 1;
	else if (keyboard_check(KEY_A) || keyboard_check(KEY_LEFT))
		this->dir = -1;
	h_mv = (keyboard_check(KEY_D) || keyboard_check(KEY_RIGHT)) - (keyboard_check(KEY_A) || keyboard_check(KEY_LEFT));
	v_mv = (keyboard_check(KEY_S) || keyboard_check(KEY_DOWN)) - (keyboard_check(KEY_W) || keyboard_check(KEY_UP));

	if (this->obj.player.attack == 0)
	{
		if (keyboard_check(KEY_SPACEBAR))
		{
			if (this->dir == 1)
				change_sprite(this, g()->asset.spr_player_attack_right);
			else
				change_sprite(this, g()->asset.spr_player_attack_left);
			this->obj.player.attack = 1;

		}
		else if (v_mv == 0 && h_mv == 0)
		{
			if (this->dir == 1)
				change_sprite(this, g()->asset.spr_player_idle_right);
			else
				change_sprite(this, g()->asset.spr_player_idle_left);
		}
		else
		{
			if (this->dir == 1)
				change_sprite(this, g()->asset.spr_player_move_right);
			else
				change_sprite(this, g()->asset.spr_player_move_left);
		}
		this->x += h_mv * 2;
		this->y += v_mv * 2;
	}

	footprint = malloc(sizeof(t_footprint));
	footprint->x = this->x - this->spr->offset_x;
	footprint->y = this->y - this->spr->offset_y;
	footprint->img = this->img_node->data;
	if (g()->global.inverted == 0)
		push_list(g()->global.straight, footprint);
	else
		push_list(g()->global.reverse, footprint);

	if (this->obj.player.attack == 1 && this->img_node->next == 0)
		this->obj.player.attack = 0;
	this->obj.player.h_mv = h_mv;
	this->obj.player.v_mv = v_mv;

	ins = place_meeting(this, this->x, this->y, ZOMBIE);
	if (this->obj.player.attack && ins)
	{
		ins->obj.zombie.die = 1;
	}
}

void		obj_player_draw(t_instance *this)
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
