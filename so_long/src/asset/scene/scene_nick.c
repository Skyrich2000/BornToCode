/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_nick.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:13:23 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:13:24 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

int	init_scene_nick(void)
{
	g()->asset.scene_nick = \
					add_scene(g()->asset.background_nick, \
					scene_nick_start, \
					scene_nick_controller, \
					scene_nick_ui, \
					scene_nick_end);
	return (OK);
}

void	scene_nick_start(void)
{
	g()->view.view_xview = 0;
	g()->view.view_yview = 0;
	g()->global.nick_index = 0;
	sl_memcpy(g()->global.nick, "                 ", NICK_SIZE);
	g()->global.nick[NICK_SIZE] = '\0';
}

void	scene_nick_controller(void)
{
	char		*ascii;
	static char	prev[50];
	static char	prev_backspace;

	ascii = (char [50]){'A', 'S', 'D', 'F', 'H', 'G', 'Z', 'X', 'C', 'V', '\0', \
					'B', 'Q', 'W', 'E', 'R', 'Y', 'T', '1', '2', '3', '4', \
					'6', '5', '\0', '9', '7', '-', '8', '0', ']', 'O', 'U', \
					'[', 'I', 'P', '\0', 'L', 'J', '\"', 'K', ':', '\0', \
					'\0', '?', 'N', 'M', '.', '\0', '\0'};
	DEBUG && printf("scene_nick_controller start\n");
	g()->global.time++;
	scr_nick_blink();
	scr_nick_keycheck(ascii, prev, prev_backspace);
	scr_nick_keysave(prev, &prev_backspace);
	DEBUG && printf("scene_nick_controller end\n");
}

void	scene_nick_ui(void)
{
	draw_text(g()->asset.font_fat_small, \
		"INPUT YOUR NICKNAME", \
		(int [2]){g()->view.view_xview + g()->view.view_wview / 2, \
					g()->view.view_yview + g()->view.view_hview / 2 - 40}, \
		(float [2]){A_CENTER, A_CENTER});
	draw_text(g()->asset.font_fat_big, \
		g()->global.nick, \
		(int [2]){g()->view.view_xview + g()->view.view_wview / 2, \
					g()->view.view_yview + g()->view.view_hview / 2}, \
		(float [2]){A_CENTER, A_CENTER});
}

void	scene_nick_end(void)
{
	destroy_all_instance();
}
