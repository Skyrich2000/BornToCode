/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:25:47 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:25:48 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

#define	SPR_IDLE	0
#define	SPR_MOVE	1
#define	SPR_ATTACK	3
#define SPR_DIE		4

#define MOVE_SPEED	2

#define X			0
#define Y			1
#define H			0
#define V			1

void	scr_player_move_auto(t_instance *this)
{
	int	h_mv;
	int	v_mv;

	h_mv = (((this->signal & SIG_MV_RIGHT) > 0) - \
								((this->signal & SIG_MV_LEFT) > 0));
	v_mv = (((this->signal & SIG_MV_DOWN) > 0) - \
								((this->signal & SIG_MV_UP) > 0));
	this->x += h_mv * MOVE_SPEED;
	this->y += v_mv * MOVE_SPEED;
	this->dir = ((this->signal & SIG_DIR_RIGHT) > 0) - \
								((this->signal & SIG_DIR_LEFT) > 0);
	if (h_mv == 0 && v_mv == 0)
		change_sprite(this, scr_player_get_spr(SPR_IDLE, \
										this->obj.player.inverted, this->dir));
	else
		change_sprite(this, scr_player_get_spr(SPR_MOVE, \
										this->obj.player.inverted, this->dir));
}

static void	_print_step(int step)
{
	char	*str;

	str = sl_itoa(step);
	write(1, "\b\b\b\b\b\b\b\b\b\b\b           \b\b\b\b\b\b\b\b\b\b\b", 33);
	write(1, "Steps : ", 7);
	write(1, str, sl_strlen(str));
	free(str);
}

static void	_move_control(t_instance *this, int prev[2], int mv[2])
{
	if (keyboard_check(KEY_SPACEBAR) && g()->global.state != S_RESTRAIGHT)
	{
		change_sprite(this, scr_player_get_spr(SPR_ATTACK, \
										this->obj.player.inverted, this->dir));
		this->obj.player.attack = 1;
		if (g()->global.state == S_INVERT)
			this->draw_time = -20;
	}
	else if (mv[V] == 0 && mv[H] == 0)
		change_sprite(this, scr_player_get_spr(SPR_IDLE, \
										this->obj.player.inverted, this->dir));
	else
	{
		_print_step(g()->global.steps++);
		change_sprite(this, scr_player_get_spr(SPR_MOVE, \
										this->obj.player.inverted, this->dir));
	}
	this->x += mv[H] * MOVE_SPEED;
	if (scr_player_collision_box(this))
		this->x = prev[X];
	this->y += mv[V] * MOVE_SPEED;
	if (scr_player_collision_box(this))
		this->y = prev[Y];
}

void	scr_player_move(t_instance *this)
{
	int	prev[2];
	int	mv[2];

	prev[X] = this->x;
	prev[Y] = this->y;
	if ((keyboard_check(KEY_D) || keyboard_check(KEY_RIGHT)))
		this->dir = 1;
	else if ((keyboard_check(KEY_A) || keyboard_check(KEY_LEFT)))
		this->dir = -1;
	mv[H] = (keyboard_check(KEY_D) || keyboard_check(KEY_RIGHT)) - \
			(keyboard_check(KEY_A) || keyboard_check(KEY_LEFT));
	mv[V] = (keyboard_check(KEY_S) || keyboard_check(KEY_DOWN)) - \
			(keyboard_check(KEY_W) || keyboard_check(KEY_UP));
	if (this->obj.player.attack == 0)
		_move_control(this, prev, mv);
	else if (this->img_node->next == 0)
		this->obj.player.attack = 0;
}
