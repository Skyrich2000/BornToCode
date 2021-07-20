#include "engine.h"

int			init_scene_play()
{
	t_scene	*new;

	new = add_scene(g()->asset.background_black, scene_play_start, scene_play_controller, scene_play_end);
	if (!new)
		return (ERROR);
	g()->asset.scene_play = new;
	return (OK);
}

void		scene_play_start()
{
	int i;
	int j;
	char *map[] = {
		"1111111111",
		"1000100001",
		"1010110101",
		"10100zb101",
		"1010110101",
		"10p0010001",
		"1111111111"
	};
	g()->global.deathcount = 0;
	g()->global.inverted = 0;
	g()->global.status = 0;
	g()->global.time = 0;
	g()->global.total_time = 0;

	i = 7;
	while (--i >= 0)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				create_wall_instance(32 + j * 32, 32 + i * 32);
			else if (map[i][j] == 'p')
				create_player_instance(32 + j * 32, 32 + i * 32);
			else if (map[i][j] == 'z')
				create_zombie_instance(32 + j * 32, 32 + i * 32);
			else if (map[i][j] == 'b')
				create_box_instance(32 + j * 32, 32 + i * 32);
		}
	}
}

static void	s_straight()
{
	t_instance	*ins;
	t_list		*node;

	g()->global.time += 1;
	if (g()->global.time > 60 * 60)
		scene_restart();
	if (keyboard_check(KEY_I))
	{
		printf("inversion start\n");
		g()->global.inverted = 1;
		g()->global.status = 1;
		g()->global.total_time = g()->global.time;

		ins = g()->instances[PLAYER]->next->data;
		create_avatar_instance(ins->obj.player.route, 0);
		create_player_instance(ins->x, ins->y);
		destroy_instance(ins);

		node = g()->instances[BOX]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			create_avatar_instance(ins->obj.box.route, 0);
			destroy_instance(ins);
		}

		// node = g()->instances[ZOMBIE_TRIGGER]->next;
		// while (node)
		// {
		// 	ins = node->data;
		// 	ins->obj.zombie_trigger.player = avatar;
		// 	node = node->next;
		// }
	}
}

static void	s_inverted()
{
	t_instance *ins;
	t_list *node;

	g()->global.time -= 1;
	if (g()->global.time < 0)
	{
		printf("re straight start\n");
		g()->global.inverted = 0;
		g()->global.status = 2;

		ins = g()->instances[PLAYER]->next->data;
		create_avatar_instance(ins->obj.player.route, 1);
		create_player_instance(ins->x, ins->y);
		destroy_instance(ins);

		node = g()->instances[ZOMBIE]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			create_avatar_instance(ins->obj.zombie.route, 1);
			destroy_instance(ins);
		}
	}
}

static void s_restraight()
{
	g()->global.time += 1;
	if (g()->global.time >= g()->global.total_time)
	{
		printf("clear \n");
		g()->global.time = 0; // temp
		g()->global.status = 3;
	}
}

static void	s_clear()
{
	t_instance *ins;

	g()->global.time += 1;
	if (g()->global.time > 60 * 3)
	{
		printf("game restart \n");
		ins = g()->instances[PLAYER]->next->data;
		free_list(ins->obj.player.route, sl_free);
		destroy_instance(ins);
		scene_restart();
	}
}

void		scene_play_controller()
{
	if (DEBUG)
		printf("scene_play_controller start\n");
	if (g()->global.status == 0) // straight
		s_straight();
	else if (g()->global.status == 1) // inverted
		s_inverted();
	else if (g()->global.status == 2) // re straight
		s_restraight();
	else if (g()->global.status == 3) // clear
		s_clear();
	if (DEBUG)
		printf("scene_play_controller end\n");
}

// TODO: free player and zombie footprint
void		scene_play_end()
{
	t_list		*node;
	t_instance	*ins;

	scene_default_end();
	node = g()->instances[AVATAR]->next;
	while (node)
	{
		ins = node->data;
		free_list(ins->obj.avatar.route, sl_free);
		node = node->next;
	}
}

