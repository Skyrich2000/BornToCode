#include "engine.h"

void	scr_player_attack(t_instance *this)
{
	t_instance *zombie;
	t_instance *box;

	zombie = place_meeting_type(this, this->x, this->y, ZOMBIE_BLUE);
	box = place_meeting_type(this, this->x, this->y, BOX_RED);
	if (this->obj.player.attack)
	{
		if (zombie)
		{
			if (zombie->condition & C_DEAD && g()->global.state == S_INVERT)
			{
				this->obj.player.reviving_zombie = zombie;
				zombie->obj.zombie.reviver = this;
				zombie->dir = this->x > zombie->x;
				zombie->condition = C_DEING;
			}
		}
		if (box)
		{
			if (box->condition & C_ALIVE && g()->global.state == S_STRAIGHT)
				box->condition = C_DEING;
		}
	}
}
