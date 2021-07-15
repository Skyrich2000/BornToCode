#include "engine.h"
#include "asset.h"

t_instance	*create_player_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_player_idle, (int [3]){PLAYER, x, y}, obj_player_step, obj_player_draw);
	if (!ins)
		return (ERROR);
	ins->obj.player.hp = 0;
	ins->obj.player.mv = 0;
	return (ins);
}

void		obj_player_step(t_instance *this)
{
	int prev_mv;
	int mv;

	prev_mv = this->obj.player.mv;
	mv = 0;
	if (keyboard_check(KEY_D))
		mv = 1;
	else if (keyboard_check(KEY_A))
		mv = -1;

	if (prev_mv != 0 && mv == 0)
		change_sprite(this, g()->asset.spr_player_idle);
	if (prev_mv != 1 && mv == 1)
		change_sprite(this, g()->asset.spr_player_move_right);
	if (prev_mv != -1 && mv == -1)
		change_sprite(this, g()->asset.spr_player_move_left);

	this->x += mv * 2;
	this->obj.player.mv = mv;
}

void		obj_player_draw(t_instance *this)
{
	static int time = 0;

	draw_sprite(this->spr, this->img_node, this->x, this->y);
	time++;
	if (time > this->img_speed)
	{
		this->img_node = this->img_node->next;
		time = 0;
	}
	if (!this->img_node)
		this->img_node = this->spr->imgs->next;
}
