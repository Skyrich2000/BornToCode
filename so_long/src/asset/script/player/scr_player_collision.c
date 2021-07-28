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
	if (ins && ins->condition & C_ALIVE && \
		g()->global.state == S_STRAIGHT)
	{
		ins->condition = C_DEING;
		--g()->global.gold_num;
	}
}

void	scr_player_collision_exit(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, EXIT);
	if (ins && ins->condition & C_ALIVE && \
		(g()->global.state == S_RESTRAIGHT || g()->global.map_index == 0) && \
		g()->global.gold_num == 0)
	{
		create_plane_instance();
		this->signal = SIG_MV_AUTO;
		ins->condition = C_DEAD;
	}
}

void	scr_player_collision_inverter(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, INVERTER);
	if (ins && ins->condition & C_ALIVE && \
		ins->obj.inverter.inverted == this->obj.player.inverted)
	{
		ins->condition = C_DEING;
		ins->signal = SIG_ACTIVE | this->signal;
	}
}

void	scr_player_collision_trigger(t_instance *this)
{
	t_instance	*ins;

	ins = place_meeting_type(this, this->x, this->y, TRIGGER);
	if (ins && \
		this->obj.player.inverted == ins->obj.trigger.inverted)
		scr_trigger(ins);
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
