#include "engine.h"
#include "asset.h"

int		scr_player_collision_box(t_instance *this)
{
	t_instance *wall;
	t_instance *box;

	wall = place_meeting_type(this, this->x, this->y, WALL);
	box = place_meeting_type(this, this->x, this->y, BOX);
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
		(g()->global.state == S_RESTRAIGHT || g()->global.invert_signal == SIG_NO_INVERT) && \
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
	if (ins)
	{
		printf("%d %d %d %d\n", ins->condition & C_ALIVE, ins->obj.inverter.inverted == this->obj.player.inverted, g()->global.inverted == S_INVERT, g()->global.time > 0);
	}
	if (ins && ins->condition & C_ALIVE && \
		ins->obj.inverter.inverted == this->obj.player.inverted && \
		g()->global.inverted == S_INVERT && g()->global.time > 0)
	{
		g()->global.text = T_WAIT;
		printf("asdf\n");
		return ;
	}
	else
		g()->global.text = 0;

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
				scr_player_die(T_HIT_BY_ZOMBIE);
			}
		}
	}
	else
		this->obj.player.reviving_zombie = 0;
}
