#include "engine.h"
#include "asset.h"

int		scr_player_collision_box(t_instance *this)
{
	t_instance *wall;
	t_instance *box;

	wall = place_meeting_type(this, this->x, this->y, WALL);
	box = place_meeting_type(this, this->x, this->y, BOX);
	this->obj.player.collision_box = box;
	return (wall || (box && box->condition & C_ALIVE));
}

void	scr_player_collision_gold(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, GOLD);
	if (ins && ins->condition & C_ALIVE)
		ins->condition = C_DEING;
}

void	scr_player_collision_inverter(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, INVERTER);
	//if (ins)
	//{
	//	printf("player inverted %d\n", this->obj.player.inverted);
	//	printf("inverter inverted %d\n", ins->obj.inverter.inverted);
	//}
	if (ins && ins->condition & C_ALIVE && ins->obj.inverter.inverted == this->obj.player.inverted)
	{
		ins->condition = C_DEING;
		//if (g()->global.state == S_STRAIGHT)
		{
			ins->signal = SIG_ACTIVE | this->signal;
		}
	}
}

void	scr_player_collision_trigger(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, TRIGGER);
	if (ins)
	{
		scr_trigger(ins, this);
	}
}


void	scr_player_collision_zombie(t_instance *this)
{
	t_instance *zombie;

	zombie = place_meeting_type(this, this->x, this->y, ZOMBIE);
	this->obj.player.collision_zombie = zombie;
	if (zombie)
	{
		if (zombie->condition & C_ALIVE)
		{
			if (zombie == this->obj.player.reviving_zombie)
				return ;
			else
			{
				if (this->obj.player.inverted == 1 && g()->global.state == S_RESTRAIGHT && this == zombie->obj.zombie.reviver)
					return ;
				scr_player_die();
			}
		}
	}
	else
		this->obj.player.reviving_zombie = 0;
}
