#include "engine.h"

int			init_scene_play()
{
	t_scene	*new;

	new = add_scene(g()->asset.background_map1, scene_play_start, scene_play_controller, scene_play_ui, scene_play_end);
	if (!new)
		return (ERROR);
	g()->asset.scene_play = new;
	return (OK);
}

void		scene_play_start()
{
	int i;
	int j;
	t_instance *ins;
	int out_dir[20];
	char	map[7][15] = {
		"11111111111111",
		"10000010000001",
		"10111011011101",
		"10111000b11101",
		"10111011011101",
		"100000010g0001",
		"11111111111111"
	};
	g()->global.inverted = S_STRAIGHT;
	g()->global.state = S_READY;
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
			else if (map[i][j] == 'z')
				create_zombie_instance(j * 32, i * 32);
			else if (map[i][j] == 'b')
				create_box_instance(j * 32, i * 32);
			else if (map[i][j] == 'g')
				create_gold_instance(j * 32, i * 32);
		}
	}

	g()->global.player = create_player_instance(2 * 32, 5 * 32, S_STRAIGHT);
	g()->global.player->signal = SIG_AUTO | SIG_DIR_RIGHT;

	out_dir[SIG_MV_RIGHT] = SIG_MV_DOWN;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_LEFT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(12 * 32, 1 * 32, S_STRAIGHT, out_dir);

	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = SIG_MV_UP;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = SIG_MV_RIGHT;
	create_inverter_instance(1 * 32, 5 * 32, S_INVERT, out_dir);

	ins = create_dummy_instance(1 * 32, 5 * 32, S_STRAIGHT, 60 * 3);
	ins->signal = SIG_AUTO | SIG_MV_RIGHT | SIG_DIR_RIGHT;
	ins = create_dummy_instance(1 * 32 - 10, 5 * 32, S_INVERT, 60 * 3);
	ins->signal = SIG_AUTO | SIG_MV_UP | SIG_DIR_RIGHT;
}

void		scene_play_controller()
{
	if (DEBUG)
		printf("scene_play_controller start\n");

	if (g()->global.state == S_READY)
		scr_state_ready();
	if (g()->global.state == S_STRAIGHT)
		scr_state_straight();
	else if (g()->global.state == S_INVERT)
		scr_state_inverted();
	else if (g()->global.state == S_RESTRAIGHT)
		scr_state_restraight();
	else if (g()->global.state == S_CLEAR)
		scr_state_clear();
	else if (g()->global.state == S_GAMEOVER)
		scr_state_gameover();

	if (keyboard_check(KEY_R))
		scene_restart();

	if (DEBUG)
		printf("scene_play_controller end\n");
}

void		scene_play_ui()
{
	int		flag;
	char	*str[2];

	if (g()->global.state == S_STRAIGHT || g()->global.state == S_READY)
		draw_sprite(g()->asset.spr_light, g()->asset.spr_light->imgs->next, g()->global.player->x, g()->global.player->y);
	flag = g()->global.state == S_STRAIGHT || g()->global.state == S_INVERT || g()->global.state == S_RESTRAIGHT;
	if (flag)
	{
		str[0] = sl_itoa(g()->global.time);
		str[1] = sl_strjoin("TIME:", str[0]);
		draw_text(g()->asset.font_default, str[1], (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview + g()->view.view_hview}, (float [2]){A_RIGHT, A_BOTTOM});
		free(str[0]);
		free(str[1]);
	}
	str[0] = sl_itoa(g()->global.deathcount);
	str[1] = sl_strjoin("DEAD:", str[0]);
	draw_text(g()->asset.font_default, str[1], (int[2]){g()->view.view_xview, g()->view.view_yview}, (float [2]){A_LEFT, A_UP});
	free(str[0]);
	free(str[1]);

	g()->view.view_xview = -16 + 14 * 32 / 2 - g()->view.view_wview / 2;
	g()->view.view_yview = -32 + 7 * 32 / 2 - g()->view.view_hview / 2;
}

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
