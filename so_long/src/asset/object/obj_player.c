/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:53 by ycha              #+#    #+#             */
/*   Updated: 2021/07/22 07:39:02 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

#define	SPR_IDLE	0
#define	SPR_MOVE	1
#define	SPR_ATTACK	2

t_sprite *scr_get_spr_player(int type, int inverted, int dir)
{
	int			idx;
	void		*asset;
	t_sprite	*spr;

	idx = 2 + (!inverted) * 8 + type * 2 + (dir != 1);
	asset = &(g()->asset);
	spr = *(t_sprite **)(asset + sizeof(void *) * idx);
	return (spr);
}

t_instance	*create_player_instance(int x, int y, int inverted)
{
	t_instance *ins;

	//printf("func -> %p\n", scr_get_spr_player(SPR_IDLE, inverted, 1));
	ins = create_instance(scr_get_spr_player(SPR_IDLE, inverted, 1), (int [3]){PLAYER, x, y}, obj_player_step, obj_player_draw);
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

static int	p_collision_box(t_instance *this)
{
	t_instance *wall;
	t_instance *box;

	wall = place_meeting_type(this, this->x, this->y, WALL);
	box = place_meeting_type(this, this->x, this->y, BOX);
	this->obj.player.collision_box = box;
	return (wall || (box && box->condition & C_ALIVE));
}

static void p_collision_zombie(t_instance *this)
{
	t_instance *zombie;

	zombie = place_meeting_type(this, this->x, this->y, ZOMBIE);
	this->obj.player.collision_zombie = zombie;
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
			change_sprite(this, scr_get_spr_player(SPR_ATTACK, this->obj.player.inverted, this->dir));
			this->obj.player.attack = 1;
			if (g()->global.state == S_INVERT)
				this->draw_time = -20;
		}
		else if (v_mv == 0 && h_mv == 0)
			change_sprite(this, scr_get_spr_player(SPR_IDLE, this->obj.player.inverted, this->dir));
		else
			change_sprite(this, scr_get_spr_player(SPR_MOVE, this->obj.player.inverted, this->dir));
		this->x += h_mv * 2;
		if (p_collision_box(this))
			this->x = this->obj.player.prev_x;
		this->y += v_mv * 2;
		if (p_collision_box(this))
			this->y = this->obj.player.prev_y;
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
				box->condition = C_DEING;
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
		p_attack(this);
		p_collision_zombie(this);
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

	if (DEBUG) printf("obj_player_draw end\n");
}
