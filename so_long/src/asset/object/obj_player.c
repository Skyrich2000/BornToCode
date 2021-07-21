/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:53 by ycha              #+#    #+#             */
/*   Updated: 2021/07/22 04:26:12 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

t_instance	*create_player_instance(int x, int y, int inverted)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_player_idle_right, (int [3]){PLAYER, x, y}, obj_player_step, obj_player_draw);
	if (!ins)
		return (ERROR);
	ins->obj.player.inverted = inverted;
	ins->obj.player.attack = 0;
	ins->obj.player.h_mv = 0;
	ins->obj.player.v_mv = 0;
	ins->obj.player.prev_x = x;
	ins->obj.player.prev_y = y;
	ins->obj.player.route = create_list();
	ins->obj.player.route_node = 0;
	ins->obj.player.collision_zombie = 0;
	ins->obj.player.collision_box = 0;
	ins->obj.player.revive_zombie = 0;
	ins->dir = 1;
	ins->condition = C_ALIVE;
	return (ins);
}

static void p_collision(t_instance *this)
{
	t_instance *wall;
	t_instance *zombie;
	t_instance *box;

	wall = place_meeting_type(this, this->x, this->y, WALL);
	box = place_meeting_type(this, this->x, this->y, BOX);
	if (wall || (box && box->condition & C_ALIVE))
	{
		this->x = this->obj.player.prev_x;
		this->y = this->obj.player.prev_y;
	}
	this->obj.player.collision_box = box;

	zombie = place_meeting_type(this, this->x, this->y, ZOMBIE);
	if (zombie)
	{
		if (zombie != this->obj.player.revive_zombie && \
			zombie->condition & C_ALIVE)
		{
			printf("GAME OVER");
			scene_restart();
		}
	}
	else
		this->obj.player.revive_zombie = 0;
	this->obj.player.collision_zombie = zombie;
}

static void	p_move(t_instance *this)
{
	int h_mv;
	int v_mv;

	this->obj.player.prev_x = this->x;
	this->obj.player.prev_y = this->y;
	if ((keyboard_check(KEY_D) || keyboard_check(KEY_RIGHT)))
		this->dir = 1;
	else if ((keyboard_check(KEY_A) || keyboard_check(KEY_LEFT)))
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
			if (g()->global.state == S_INVERT)
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

static void	p_attack(t_instance *this)
{
	t_instance *zombie;
	t_instance *box;

	zombie = this->obj.player.collision_zombie;
	box = this->obj.player.collision_box;
	if (this->obj.player.attack)
	{
		if (zombie)
		{
			if (zombie->condition & C_DEAD && g()->global.state == S_INVERT)
			{
				zombie->dir = this->x > zombie->x;
				zombie->condition = C_DEING;
				this->obj.player.revive_zombie = zombie;
			}
		}
		if (box)
		{
			if (box->condition & C_ALIVE && g()->global.state == S_STRAIGHT)
			{
				box->condition = C_DEING;
			}
		}
	}
}


void		obj_player_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_player_step start\n");

	if (!(this->condition & C_AVATAR))
	{
		p_move(this);
		p_collision(this);
		p_attack(this);
		scr_save_footprint(this, this->obj.player.route);
	}
	else
		scr_load_footprint(this, &this->obj.player.route_node, this->obj.player.inverted);

	if (DEBUG)
		printf("obj_player_step end\n");
}

void		obj_player_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_player_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);

	if (!(this->condition & C_AVATAR))
		scr_animation(this);

	if (DEBUG)
		printf("obj_player_draw end\n");
}
