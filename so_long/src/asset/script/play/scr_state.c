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
		if (g()->global.player != 0)
			scr_player_die();
		else
			g()->global.state = S_CLEAR;
	}
}

void	scr_state_clear()
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 3)
	{
		g()->global.map_index++;
		if (g()->global.map_index >= 2) //MAP_SIZE)
		{
			scr_save_rank(g()->global.nick, g()->global.time, g()->global.deathcount);
			scene_change(g()->asset.scene_rank);
		}
		else
		{
			scene_restart();
		}
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
