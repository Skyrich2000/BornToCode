#include "engine.h"

int			init_scene_play()
{
	g()->asset.scene_play = add_scene(g()->asset.background_nick, scene_play_start, scene_play_controller, scene_play_ui, scene_play_end);
	if (!g()->asset.scene_play)
		return (ERROR);
	return (OK);
}

void		scene_play_start()
{
	if (DEBUG)
		printf("scene_play_start start\n");

	g()->global.inverted = S_STRAIGHT;
	g()->global.state = S_READY;
	g()->global.time = 0;
	g()->global.steps = 0;
	g()->global.delay = 0;
	g()->global.total_time = 0;
	g()->global.invert_signal = 0;
	g()->global.gold_num = 0;
	g()->asset.maps[g()->global.map_index](&g()->global.map_width, &g()->global.map_height);
	g()->view.view_xview = -16 + g()->global.map_width * 32 / 2 - g()->view.view_wview / 2;
	g()->view.view_yview = -32 + g()->global.map_height * 32 / 2 - g()->view.view_hview / 2;

	if (DEBUG)
		printf("scene_play_start end\n");
}

// TODO: move view port if map is big
void		scene_play_controller()
{
	if (DEBUG)
		printf("scene_play_controller start\n");

	if (g()->global.state == S_READY)
		scr_state_ready();
	else if (g()->global.state == S_STRAIGHT)
		scr_state_straight();
	else if (g()->global.state == S_INVERT)
		scr_state_inverted();
	else if (g()->global.state == S_RESTRAIGHT)
		scr_state_restraight();
	else if (g()->global.state == S_CLEAR)
		scr_state_clear();
	else if (g()->global.state == S_GAMEOVER)
		scr_state_gameover();

	if (g()->global.state != S_READY && keyboard_check(KEY_R))
		scr_player_die();

	if (DEBUG)
		printf("scene_play_controller end\n");
}

void		scene_play_ui()
{
	if (DEBUG)
		printf("scene_play_ui start\n");
	char	*str[2];

	draw_img(g()->canvas.img, g()->global.map_width * 32 - 32 + 16, -32);
	draw_img(g()->canvas.img, -16, g()->global.map_height * 32 - 32);

	if (g()->global.map_index != 0)
	{
		if (g()->global.state == S_READY)
			draw_sprite(g()->asset.spr_light_dark, g()->asset.spr_light_dark->imgs->next, g()->global.player->x + 3, g()->global.player->y - 19);
		if (g()->global.state == S_STRAIGHT || g()->global.state == S_INVERT)
				draw_sprite(g()->asset.spr_light, g()->asset.spr_light->imgs->next, g()->global.player->x + 3, g()->global.player->y - 10);
	}
	else if (g()->global.player)
	{
		g()->view.view_xview = g()->global.player->x - g()->view.view_wview / 2;
		g()->view.view_yview = g()->global.player->y - g()->view.view_hview / 2;
	}

	if (g()->global.state == S_READY)
		draw_text(g()->asset.font_fat_small, "S_READY", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_RIGHT, A_UP});
	if (g()->global.state == S_STRAIGHT)
		draw_text(g()->asset.font_fat_small, "S_STRAIGHT", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_RIGHT, A_UP});
	else if (g()->global.state == S_INVERT)
		draw_text(g()->asset.font_fat_small, "S_INVERT", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_RIGHT, A_UP});
	else if (g()->global.state == S_RESTRAIGHT)
		draw_text(g()->asset.font_fat_small, "S_RESTRAIGHT", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_RIGHT, A_UP});
	else if (g()->global.state == S_CLEAR)
		draw_text(g()->asset.font_fat_small, "S_CLEAR", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_RIGHT, A_UP});
	else if (g()->global.state == S_GAMEOVER)
		draw_text(g()->asset.font_fat_small, "S_GAMEOVER", (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview}, (float [2]){A_RIGHT, A_UP});

	str[0] = sl_itoa(g()->global.time);
	str[1] = sl_strjoin("TIME:", str[0]);
	draw_text(g()->asset.font_fat_small, str[1], (int[2]){g()->view.view_xview + g()->view.view_wview, g()->view.view_yview + g()->view.view_hview}, (float [2]){A_RIGHT, A_BOTTOM});
	free(str[0]);
	free(str[1]);

	str[0] = sl_itoa(g()->global.deathcount);
	str[1] = sl_strjoin("DEAD:", str[0]);
	draw_text(g()->asset.font_fat_big, str[1], (int[2]){g()->view.view_xview, g()->view.view_yview}, (float [2]){A_LEFT, A_UP});
	free(str[0]);
	free(str[1]);

	draw_text(g()->asset.font_fat_big, g()->global.nick, (int[2]){g()->view.view_xview, g()->view.view_yview + g()->view.view_hview}, (float [2]){A_LEFT, A_BOTTOM});
	if (DEBUG)
		printf("scene_play_ui end\n");
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
