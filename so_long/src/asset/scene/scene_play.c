/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_play.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:17:40 by su                #+#    #+#             */
/*   Updated: 2021/08/10 18:44:01 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define VIEW_SPEED	10

int	init_scene_play(void)
{
	g()->asset.scene_play = \
			add_scene(g()->asset.background_nick, \
			scene_play_start, \
			scene_play_controller, \
			scene_play_ui, \
			scene_play_end);
	return (OK);
}

void	scene_play_start(void)
{
	DEBUG && printf("scene_play_start start\n");
	g()->global.tutorial = 0;
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
	g()->asset.maps[g()->global.map_index](&g()->global.map_width, \
											&g()->global.map_height);
	g()->global.view_xview_aim = \
			-16 + g()->global.map_width * 32 / 2 - g()->view.view_wview / 2;
	g()->global.view_yview_aim = \
			-32 + g()->global.map_height * 32 / 2 - g()->view.view_hview / 2;
	g()->view.view_xview = g()->global.view_xview_aim;
	g()->view.view_yview = g()->global.view_yview_aim;
	DEBUG && printf("scene_play_start end\n");
}

void	scene_play_controller(void)
{
	DEBUG && printf("scene_play_controller start\n");
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
		scr_player_die(TXT_GAME_OVER, g()->global.player);
	g()->view.view_xview += \
			(g()->global.view_xview_aim - g()->view.view_xview) / VIEW_SPEED;
	g()->view.view_yview += \
			(g()->global.view_yview_aim - g()->view.view_yview) / VIEW_SPEED;
	DEBUG && printf("scene_play_controller end\n");
}

void	scene_play_ui(void)
{
	int		len;
	int		up_pad;
	int		down_pad;

	DEBUG && printf("scene_play_ui start\n");
	len = sl_strlen(g()->global.nick);
	up_pad = 10;
	down_pad = up_pad + 19 + 10;
	draw_img(g()->canvas.img, g()->global.map_width * 32 - 32 + 16, -32);
	draw_img(g()->canvas.img, -16, g()->global.map_height * 32 - 32);
	scr_ui_light();
	scr_ui_nick(10, up_pad, down_pad);
	scr_ui_state(10, len, up_pad);
	scr_ui_map(len * 19 + (640 - len * 19) / 7 * 2, up_pad, down_pad);
	scr_ui_step(len * 19 + (640 - len * 19) / 7 * 4, up_pad, down_pad);
	scr_ui_death(640 - 10, up_pad, down_pad);
	if (g()->global.text == 0)
		scr_ui_time();
	else
		scr_ui_text();
	DEBUG && printf("scene_play_ui end\n");
}

void	scene_play_end(void)
{
	t_list		*node;
	t_instance	*ins;
	int			*type;
	int			i;

	DEBUG && printf("scene_play_end start\n");
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
	DEBUG && printf("scene_play_end end\n");
}
