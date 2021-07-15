#include "engine.h"
#include "asset.h"

t_instance	*create_player_instance(int x, int y)
{
	t_instance *new;

	new = (t_instance *)malloc(sizeof(t_instance));
	if (!new)
		return (ERROR);
	new->type = 0;
	new->obj.player.hp = 0;
	new->spr = g()->spr_player_idle;
	new->img_node = new->spr->imgs->next;
	new->img_speed = 10;
	new->x = x;
	new->y = y;
	new->step = obj_player_step;
	new->draw = obj_player_draw;
	if (!push_list(g()->instances, new))
		return (ERROR);
	return (new);
}

void		obj_player_step(t_instance *this)
{
	static int time = 0;
	static int mv = 0;

	time++;
	if (time > 120)
	{
		if (mv == 0) // if stop
		{
			this->spr = g()->spr_player_move_right;
			this->img_node = this->spr->imgs->next;
			this->img_speed = 5;
			mv = 1; // go right
		}
		else if (mv == 1) // if going right
		{
			this->spr = g()->spr_player_idle;
			this->img_node = this->spr->imgs->next;
			this->img_speed = 10;
			mv = 0; // stop
		}
		time = 0;
	}

	if (mv)
		this->x += 1;
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
