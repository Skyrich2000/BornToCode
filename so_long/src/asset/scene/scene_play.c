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
	g()->global.inverted = S_STRAIGHT;
	g()->global.state = S_STRAIGHT;
	g()->global.time = 0;
	g()->global.total_time = 0;

	i = -1;
	while (++i < 7)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				create_wall_instance(j * 32, i * 32);
			else if (map[i][j] == 'p')
				g()->global.player = create_player_instance(j * 32, i * 32, S_STRAIGHT);
			else if (map[i][j] == 'z')
				create_zombie_instance(j * 32, i * 32);
			else if (map[i][j] == 'b')
				create_box_instance(j * 32, i * 32);
		}
	}

	g()->view.view_xview = -16 + j * 32 / 2 - g()->view.view_wview / 2;
	g()->view.view_yview = -32 + i * 32 / 2 - g()->view.view_hview / 2;
}


static void s_avatarize(int type)
{
	t_instance	*ins;
	t_list		*node;
	t_list		**route_node;

	node = g()->instances[type]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins->condition & C_AVATAR)
			continue ;
		ins->condition |= C_AVATAR;
		route_node = scr_get_route_node(ins, type);
		*route_node = scr_get_route(ins, type)->next;
	}
}

static void	s_straight()
{
	t_instance	*ins;

	g()->global.time += 1;
	if (g()->global.time > 60 * 60)
	{
		printf("time over..?");
		scene_restart();
	}
	if (keyboard_check(KEY_I))
	{
		printf("inversion start\n");
		g()->global.inverted = S_INVERT;
		g()->global.state = S_INVERT;
		g()->global.total_time = g()->global.time;

		s_avatarize(PLAYER);
		s_avatarize(BOX);

		ins = g()->global.player;
		g()->global.player = create_player_instance(ins->x, ins->y, S_INVERT);
	}
}

static void	s_inverted()
{
	t_instance	*ins;

	g()->global.time -= 1;
	if (g()->global.time < 0)
	{
		printf("re straight start\n");
		g()->global.inverted = S_STRAIGHT;
		g()->global.state = S_RESTRAIGHT;

		s_avatarize(PLAYER);
		s_avatarize(ZOMBIE);

		ins = g()->global.player;
		g()->global.player = create_player_instance(ins->x, ins->y, S_STRAIGHT);
	}
}

static void s_restraight()
{
	g()->global.time += 1;
	if (g()->global.time >= g()->global.total_time)
	{
		printf("clear \n");
		g()->global.time = 0; // temp
		g()->global.state = S_CLEAR;
	}
}

static void	s_clear()
{
	g()->global.time += 1;
	if (g()->global.time > 60 * 3)
	{
		printf("game restart \n");
		scene_restart();
	}
}

void		scene_play_controller()
{
	if (DEBUG)
		printf("scene_play_controller start\n");

	if (g()->global.state == S_STRAIGHT)
		s_straight();
	else if (g()->global.state == S_INVERT)
		s_inverted();
	else if (g()->global.state == S_RESTRAIGHT)
		s_restraight();
	else if (g()->global.state == S_CLEAR)
		s_clear();

	if (DEBUG)
		printf("scene_play_controller end\n");
}

// TODO: free player and zombie footprint
void		scene_play_end()
{
	t_list		*node;
	t_instance	*ins;
	int			*type;
	int			i;

	type = (int [3]){PLAYER, ZOMBIE, BOX};
	i = -1;
	while (++i < 3)
	{
		node = g()->instances[type[i]]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			free_list(scr_get_route(ins, type[i]), sl_free);
		}
	}
	destroy_all_instance();
}
