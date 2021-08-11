/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_ui_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:24:35 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:24:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

void	scr_ui_nick(int x1, int up_pad, int down_pad)
{
	char	*str;

	draw_text(g()->asset.font_fat_small, \
									g()->global.nick, \
									(int [2]){g()->view.view_xview + x1, \
									g()->view.view_yview + up_pad}, \
									(float [2]){A_LEFT, A_UP});
	if (g()->global.tutorial)
		draw_text(g()->asset.font_fat_small, \
									"TUTORIAL", \
									(int [2]){g()->view.view_xview + x1, \
									g()->view.view_yview + down_pad}, \
									(float [2]){A_LEFT, A_UP});
	else
	{
		str = sl_itoa(g()->global.time_all_lv);
		draw_text(g()->asset.font_fat_small, \
									str, \
									(int [2]){g()->view.view_xview + x1, \
									g()->view.view_yview + down_pad}, \
									(float [2]){A_LEFT, A_UP});
		free(str);
	}
}

void	scr_ui_state(int x1, int len, int up_pad)
{
	t_sprite	*spr;

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
	draw_sprite(spr, spr->imgs->next, g()->view.view_xview + x1 + len * 19 + 6, \
										g()->view.view_yview + up_pad + 1);
}

void	scr_ui_death(int x4, int up_pad, int down_pad)
{
	char	*str;

	draw_text(g()->asset.font_fat_small, \
									"DEATH", \
									(int [2]){g()->view.view_xview + x4, \
									g()->view.view_yview + up_pad}, \
									(float [2]){A_RIGHT, A_UP});
	str = sl_itoa(g()->global.deathcount);
	draw_text(g()->asset.font_fat_small, \
									str, \
									(int [2]){g()->view.view_xview + x4, \
									g()->view.view_yview + down_pad}, \
									(float [2]){A_RIGHT, A_UP});
	free(str);
}

void	scr_ui_step(int x3, int up_pad, int down_pad)
{
	char	*str;

	draw_text(g()->asset.font_fat_small, \
								"STEP", \
								(int [2]){g()->view.view_xview + x3, \
								g()->view.view_yview + up_pad}, \
								(float [2]){A_CENTER, A_UP});
	str = sl_itoa(g()->global.steps);
	draw_text(g()->asset.font_fat_small, \
								str, \
								(int [2]){g()->view.view_xview + x3, \
								g()->view.view_yview + down_pad}, \
								(float [2]){A_CENTER, A_UP});
	free(str);
}

void	scr_ui_map(int x2, int up_pad, int down_pad)
{
	char	*str;

	draw_text(g()->asset.font_fat_small, \
								"MAP", \
								(int [2]){g()->view.view_xview + x2, \
								g()->view.view_yview + up_pad}, \
								(float [2]){A_CENTER, A_UP});
	str = sl_itoa(g()->global.map_index);
	draw_text(g()->asset.font_fat_small, \
								str, \
								(int [2]){g()->view.view_xview + x2, \
								g()->view.view_yview + down_pad}, \
								(float [2]){A_CENTER, A_UP});
	free(str);
}
