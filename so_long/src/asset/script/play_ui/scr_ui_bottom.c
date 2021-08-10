/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_ui_bottom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:17:40 by su                #+#    #+#             */
/*   Updated: 2021/08/10 19:01:14 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

void	scr_ui_time(void)
{
	char	*str[5];

	str[0] = sl_itoa(g()->global.time / 60);
	str[1] = sl_itoa((double)(sl_abs(g()->global.time) % 60) / 60 * 100);
	str[2] = sl_strjoin(str[0], "\'");
	str[3] = sl_strjoin(str[2], str[1]);
	str[4] = sl_strjoin(str[3], "\"");
	draw_text(g()->asset.font_fat_big, str[4], \
				(int [2]){g()->view.view_xview + g()->view.view_wview / 2, \
				g()->view.view_yview + g()->view.view_hview - 16}, \
				(float [2]){A_CENTER, A_BOTTOM});
	sl_free_arr5(str);
}

void	scr_ui_text(void)
{
	char	*str;

	str = "GAME OVER";
	if (g()->global.text == TXT_TIME_OVER)
		str = "TIME OVER";
	else if (g()->global.text == TXT_HIT_BY_ZOMBIE)
		str = "HIT BY TOAST";
	else if (g()->global.text == TXT_MEET_MYSELF)
		str = "MEET MYSELF";
	else if (g()->global.text == TXT_TENET_ERROR)
		str = "TOAST IS NOT DEAD";
	else if (g()->global.text == TXT_WAIT)
		str = "WAIT";
	draw_text(g()->asset.font_fat_big, str, \
				(int [2]){g()->view.view_xview + g()->view.view_wview / 2, \
				g()->view.view_yview + g()->view.view_hview - 16}, \
				(float [2]){A_CENTER, A_BOTTOM});
}
