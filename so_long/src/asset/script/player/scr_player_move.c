#include "engine.h"

#define	SPR_IDLE	0
#define	SPR_MOVE	1
#define	SPR_ATTACK	3
#define SPR_DIE		4

void	scr_player_move_auto(t_instance *this)
{
	int h_mv;
	int v_mv;

	h_mv = (((this->signal & SIG_MV_RIGHT) > 0) - ((this->signal & SIG_MV_LEFT) > 0));
	v_mv = (((this->signal & SIG_MV_DOWN) > 0) - ((this->signal & SIG_MV_UP) > 0));
	this->x += h_mv * 2;
	this->y += v_mv * 2;
	this->dir = ((this->signal & SIG_DIR_RIGHT) > 0) - ((this->signal & SIG_DIR_LEFT) > 0);
	if (h_mv == 0 && v_mv == 0)
		change_sprite(this, scr_player_get_spr(SPR_IDLE, this->obj.player.inverted, this->dir));
	else
		change_sprite(this, scr_player_get_spr(SPR_MOVE, this->obj.player.inverted, this->dir));
}

void	scr_player_move(t_instance *this)
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
			change_sprite(this, scr_player_get_spr(SPR_ATTACK, this->obj.player.inverted, this->dir));
			this->obj.player.attack = 1;
			if (g()->global.state == S_INVERT)
				this->draw_time = -20;
		}
		else if (v_mv == 0 && h_mv == 0)
			change_sprite(this, scr_player_get_spr(SPR_IDLE, this->obj.player.inverted, this->dir));
		else
		{
			g()->global.steps++;
			change_sprite(this, scr_player_get_spr(SPR_MOVE, this->obj.player.inverted, this->dir));
		}
		this->x += h_mv * 2;
		if (scr_player_collision_box(this))
			this->x = this->obj.player.prev_x;
		this->y += v_mv * 2;
		if (scr_player_collision_box(this))
			this->y = this->obj.player.prev_y;
	}

	this->obj.player.h_mv = h_mv;
	this->obj.player.v_mv = v_mv;
	if (this->obj.player.attack == 1 && this->img_node->next == 0)
		this->obj.player.attack = 0;
}
