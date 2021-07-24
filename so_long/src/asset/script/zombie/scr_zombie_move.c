#include "engine.h"


void	scr_zombie_move(t_instance *this)
{
	t_instance *ins;

	//0010
	if (this->condition & C_DEING)
	{
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_die_right_reverse);
		else
			change_sprite(this, g()->asset.spr_zombie_die_left_reverse);
		if (this->img_node->next == 0)
			this->condition = C_ALIVE;
	}
	else if (this->condition & C_ALIVE)
	{
		ins = g()->instances[PLAYER]->next->data;
		if (ins && point_distance(this->x, this->y, ins->x, ins->y) < 50 * 50)
		{
			this->dir = 0;
			if (ins->x > this->x)
				this->dir = 1;
		}
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_zombie_idle_right_reverse);
		else
			change_sprite(this, g()->asset.spr_zombie_idle_left_reverse);
	}
}