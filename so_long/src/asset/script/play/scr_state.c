#include "engine.h"

void	scr_state_ready()
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 2)
	{
		g()->global.state = S_STRAIGHT;
		g()->global.player->signal = 0;
	}
}

void	scr_state_straight()
{
	g()->global.time += 1;
	if (g()->global.time > 4200)
	{
		printf("time over");
		g()->global.view_xview_aim = g()->global.player->x - g()->view.view_wview / 2;
		g()->global.view_yview_aim = g()->global.player->y - g()->view.view_hview / 2;
		scr_player_die(TXT_TIME_OVER);
	}
	if (g()->global.invert_signal == SIG_ACTIVE)
	{
		g()->global.state = S_INVERT;
		g()->global.max_time = g()->global.time;
		g()->global.invert_signal = SIG_NORMAL;

		scr_avatarize(BOX_RED);
		scr_avatarize(GOLD_RED);
	}
}

void	scr_state_inverted()
{
	t_instance	*dead_zombie;
	t_instance	*ins;
	t_list		*node;

	g()->global.time -= 1;
	if (g()->global.time < -4200)
	{
		printf("time over");
		g()->global.view_xview_aim = g()->global.player->x - g()->view.view_wview / 2;
		g()->global.view_yview_aim = g()->global.player->y - g()->view.view_hview / 2;
		scr_player_die(TXT_TIME_OVER);
	}
	if (g()->global.invert_signal == SIG_ACTIVE)
	{
		g()->global.state = S_RESTRAIGHT;
		g()->global.invert_signal = SIG_NORMAL;

		scr_avatarize(ZOMBIE_BLUE);
		dead_zombie = 0;
		node = g()->instances[ZOMBIE_BLUE]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			if (ins->condition & C_DEAD)
			{
				ins->condition = C_ALIVE;
				dead_zombie = ins;
			}
		}
		if (dead_zombie)
		{
			g()->global.view_xview_aim = dead_zombie->x - g()->view.view_wview / 2;
			g()->global.view_yview_aim = dead_zombie->y - g()->view.view_hview / 2;
			scr_player_die(TXT_TENET_ERROR);
		}
	}
}

void	scr_state_restraight()
{
	t_list		*node;
	t_instance	*ins;

	g()->global.time += 1;
	if (g()->global.time == g()->global.max_time)
	{
		node = g()->instances[PLAYER]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			if (ins != g()->global.player)
				destroy_instance(ins);
		}
	}
	if (g()->global.time > g()->global.max_time && g()->global.player == 0)
	{
		g()->global.state = S_CLEAR;
		g()->global.delay = 0;
	}
}

void	scr_state_clear()
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 3)
	{
		g()->global.map_index++;
		if (!g()->global.tutorial)
			g()->global.time_all_lv += g()->global.time;
		if (g()->global.map_index >= MAP_SIZE)
		{
			scr_save_rank(g()->global.nick, g()->global.time_all_lv, g()->global.deathcount);
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
	if (g()->global.delay > 60 * 4)
	{
		printf("game restart \n");
		scene_restart();
	}
}
