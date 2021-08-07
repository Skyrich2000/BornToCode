#include "engine.h"

int			init_scene_play()
{
	g()->asset.scene_play = add_scene(g()->asset.background_nick, scene_play_start, scene_play_controller, scene_play_ui, scene_play_end);
	return (OK);
}

void		scene_play_start()
{
	if (DEBUG)
		printf("scene_play_start start\n");

	g()->global.steps = 0;
	g()->global.time = 0;
	g()->global.delay = 0;
	g()->global.max_time = 0;
	g()->global.state = S_READY;
	g()->global.text = 0;
	g()->global.inverted = S_STRAIGHT;
	g()->global.invert_signal = SIG_NORMAL;
	g()->global.gold_num = 0;
	g()->global.darkness = 0;
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
		scr_player_die(TXT_GAME_OVER);

	if (DEBUG)
		printf("scene_play_controller end\n");
}


// TODO: make light more lighter
void		scene_play_ui()
{

	if (DEBUG)
		printf("scene_play_ui start\n");

	draw_img(g()->canvas.img, g()->global.map_width * 32 - 32 + 16, -32);
	draw_img(g()->canvas.img, -16, g()->global.map_height * 32 - 32);

	if (g()->global.state == S_STRAIGHT || g()->global.state == S_INVERT)
		draw_sprite(g()->asset.spr_light, g()->asset.spr_light->imgs->next, g()->global.player->x + 3, g()->global.player->y - 19);

	int i;
	i = g()->global.darkness;
	while (--i > 0)
		draw_sprite(g()->asset.spr_light_5, g()->asset.spr_light->imgs->next, g()->global.player->x + 3, g()->global.player->y - 19);

	if (g()->global.player && g()->global.invert_signal == SIG_NO_INVERT)
	{
		g()->view.view_xview = g()->global.player->x - g()->view.view_wview / 2;
		g()->view.view_yview = g()->global.player->y - g()->view.view_hview / 2;
	}

	// nick(state), map, step, death
	// 1280 		 0	 0		  0
	char	*str[4];
	int		len = sl_strlen(g()->global.nick);
	int		up_pad = 10;
	int		down_pad = up_pad + 19 + 10;
	int		x1 = 10;
	int		x2 = len * 19 + (640 - len * 19) / 7 * 2;
	int		x3 = len * 19 + (640 - len * 19) / 7 * 4;
	int		x4 = 640 - 10;

	draw_text(g()->asset.font_fat_small, g()->global.nick, (int[2]){g()->view.view_xview + x1, g()->view.view_yview + up_pad}, (float [2]){A_LEFT, A_UP});

	str[0] = sl_itoa(g()->global.time_all_lv);
	draw_text(g()->asset.font_fat_small, str[0], (int[2]){g()->view.view_xview + x1, g()->view.view_yview + down_pad}, (float [2]){A_LEFT, A_UP});
	free(str[0]);

	t_sprite *spr;

	spr = g()->asset.spr_ready;
	if (g()->global.state == S_STRAIGHT)
		spr = g()->asset.spr_straight;
	else if (g()->global.state == S_INVERT)
		spr = g()->asset.spr_invert;
	else if (g()->global.state == S_RESTRAIGHT)
		spr = g()->asset.spr_straight;
	else if (g()->global.state == S_CLEAR)
		spr = g()->asset.spr_clear;
	else if (g()->global.state == S_GAMEOVER)
		spr = g()->asset.spr_gameover;

	draw_sprite(spr, spr->imgs->next, g()->view.view_xview + x1 + len * 19 + 6, g()->view.view_yview + up_pad + 1);

	draw_text(g()->asset.font_fat_small, "MAP", (int[2]){g()->view.view_xview + x2, g()->view.view_yview + up_pad}, (float [2]){A_CENTER, A_UP});

	str[0] = sl_itoa(g()->global.map_index);
	draw_text(g()->asset.font_fat_small, str[0], (int[2]){g()->view.view_xview + x2, g()->view.view_yview + down_pad}, (float [2]){A_CENTER, A_UP});
	free(str[0]);

	draw_text(g()->asset.font_fat_small, "STEP", (int[2]){g()->view.view_xview + x3, g()->view.view_yview + up_pad}, (float [2]){A_CENTER, A_UP});

	str[0] = sl_itoa(g()->global.steps);
	draw_text(g()->asset.font_fat_small, str[0], (int[2]){g()->view.view_xview + x3, g()->view.view_yview + down_pad}, (float [2]){A_CENTER, A_UP});
	free(str[0]);

	draw_text(g()->asset.font_fat_small, "DEATH", (int[2]){g()->view.view_xview + x4, g()->view.view_yview + up_pad}, (float [2]){A_RIGHT, A_UP});

	str[0] = sl_itoa(g()->global.deathcount);
	draw_text(g()->asset.font_fat_small, str[0], (int[2]){g()->view.view_xview + x4, g()->view.view_yview + down_pad}, (float [2]){A_RIGHT, A_UP});
	free(str[0]);

	if (g()->global.text == 0)
	{
		str[0] = sl_itoa(g()->global.time / 60);
		str[1] = sl_itoa(g()->global.time % 60);
		str[2] = sl_strjoin(str[0], ":");
		str[3] = sl_strjoin(str[2], str[1]);
		draw_text(g()->asset.font_fat_big, str[3], (int[2]){g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_hview - 16}, (float [2]){A_CENTER, A_BOTTOM});
		free(str[0]);
		free(str[1]);
		free(str[2]);
		free(str[3]);
	}
	else
	{
		str[0] = "GAME OVER";
		if (g()->global.text == TXT_TIME_OVER)
			str[0] = "TIME OVER";
		else if (g()->global.text == TXT_HIT_BY_ZOMBIE)
			str[0] = "HIT BY ZOMBIE_B";
		else if (g()->global.text == TXT_MEET_MYSELF)
			str[0] = "MEET MYSELF";
		else if (g()->global.text == TXT_WAIT)
			str[0] = "WAIT";
		draw_text(g()->asset.font_fat_big, str[0], (int[2]){g()->view.view_xview + g()->view.view_wview / 2, g()->view.view_yview + g()->view.view_hview - 16}, (float [2]){A_CENTER, A_BOTTOM});
	}

	if (DEBUG)
		printf("scene_play_ui end\n");
}

void		scene_play_end()
{
	t_list		*node;
	t_instance	*ins;
	int			*type;
	int			i;

	type = (int [3]){PLAYER, ZOMBIE_BLUE, BOX_RED};
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
