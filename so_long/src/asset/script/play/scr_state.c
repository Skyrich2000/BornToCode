#include "engine.h"

void	scr_state_ready()
{
	g()->global.time += 1;
	if (g()->global.time > 60 * 2)
	{
		g()->global.state = S_STRAIGHT;
		g()->global.player->signal = 0;
	}
}

void	scr_state_straight()
{
	//t_instance *ins;
	g()->global.time += 1;
	if (g()->global.time > 60 * 60)
	{
		printf("time over..?");
		scene_restart();
	}
	if (g()->global.invert_signal == 1)
	{
		g()->global.state = S_INVERT;
		g()->global.total_time = g()->global.time;
		g()->global.invert_signal = 0;

		scr_avatarize(BOX);
		scr_avatarize(GOLD);
	}
}

void	scr_state_inverted()
{
	t_instance	*ins;
	t_list		*node;

	g()->global.time -= 1;
	if (g()->global.invert_signal == 1)
	{
		printf("re straight start\n");
		g()->global.state = S_RESTRAIGHT;
		g()->global.invert_signal = 0;

		scr_avatarize(ZOMBIE);
		node = g()->instances[ZOMBIE]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			if (ins->condition & C_DEAD)
				ins->condition = C_ALIVE;
		}
	}
}

void	scr_state_restraight()
{
	g()->global.time += 1;
	if (g()->global.time >= g()->global.total_time)
	{
		printf("clear \n");
		g()->global.delay = 0; // temp
		g()->global.state = S_CLEAR;
	}
}

void	scr_state_clear()
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 3)
	{
		if (g()->global.map_index < MAP_SIZE - 1)
		{
			g()->global.map_index++;
			scene_restart();
		}
		else
			scene_change(g()->asset.scene_rank);
	}
}

void	scr_state_gameover()
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 3)
	{
		printf("game restart \n");
		scene_restart();
	}
}
