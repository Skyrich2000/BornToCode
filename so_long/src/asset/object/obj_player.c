/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:53 by ycha              #+#    #+#             */
/*   Updated: 2021/07/21 04:14:36 by ycha             ###   ########.fr       */
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
	ins->obj.player.route = create_list();
	ins->dir = 1;
	return (ins);
}

static void p_collision(t_instance *this)
{
	t_instance *ins;
	t_list	*node;

	if (place_meeting_type(this, this->x, this->y, WALL))
	{
		this->x = this->obj.player.prev_x;
		this->y = this->obj.player.prev_y;
		return ;
	}
	node = g()->instances[BOX]->next;
	while (node)
	{
		ins = node->data;
		if (place_meeting(this, this->x, this->y, ins) && ins->obj.box.status != 2)
		{
			this->x = this->obj.player.prev_x;
			this->y = this->obj.player.prev_y;
			return ;
		}
		node = node->next;
	}

	ins = place_meeting_type(this, this->x, this->y, ZOMBIE);
	if (ins && ins->obj.zombie.status == 2)
	{
		printf("GAME OVER");
		scene_restart();
	}
}

static void	p_move(t_instance *this)
{
	int h_mv;
	int v_mv;

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
			if (g()->global.status == 1)
				this->draw_time = -20;
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

	this->obj.player.h_mv = h_mv;
	this->obj.player.v_mv = v_mv;
	if (this->obj.player.attack == 1 && this->img_node->next == 0)
		this->obj.player.attack = 0;
}

static void	p_footprint(t_instance *this)
{
	t_footprint *footprint;

	footprint = malloc(sizeof(t_footprint));
	footprint->x = this->x;
	footprint->y = this->y;
	footprint->spr = this->spr;
	footprint->img_node = this->img_node;
	push_list(this->obj.player.route, footprint);
}

static void	p_attack(t_instance *this)
{
	t_instance *ins;

	if (this->obj.player.attack)
	{
		ins = place_meeting_type(this, this->x, this->y, ZOMBIE);
		if (ins)
		{
			if (ins->obj.zombie.status == 0 && g()->global.status == 1)
			{
				ins->dir = this->x > ins->x;
				ins->obj.zombie.status = 1;
			}
		}

		ins = place_meeting_type(this, this->x, this->y, BOX);
		if (ins)
		{
			if (ins->obj.box.status == 0 && g()->global.status == 0)
			{
				ins->obj.box.status = 1;
			}
		}
	}
}

void		obj_player_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_player_step start\n");
	p_move(this);
	p_collision(this);
	p_footprint(this);
	p_attack(this);
	if (DEBUG)
		printf("obj_player_step end\n");
}

void		obj_player_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_player_draw start\n");
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	this->draw_time++;
	if (this->draw_time > this->spr->img_speed)
	{
		this->img_node = this->img_node->next;
		this->draw_time = 0;
	}
	if (!this->img_node)
		this->img_node = this->spr->imgs->next;
	if (DEBUG)
		printf("obj_player_draw end\n");
}
