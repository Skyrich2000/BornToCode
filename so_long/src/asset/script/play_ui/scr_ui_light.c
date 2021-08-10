/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_ui_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:17:40 by su                #+#    #+#             */
/*   Updated: 2021/08/10 18:31:56 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_ui_light(void)
{
	int	i;

	if (g()->global.state == S_STRAIGHT || g()->global.state == S_INVERT)
		draw_sprite(g()->asset.spr_light, g()->asset.spr_light->imgs->next, \
					g()->global.player->x + 3, g()->global.player->y - 19);
	i = g()->global.darkness;
	while (--i > 0)
		draw_sprite(g()->asset.spr_light_5, g()->asset.spr_light->imgs->next, \
		g()->global.player->x + 3, g()->global.player->y - 19);
	if (g()->global.player && g()->global.invert_signal == SIG_NO_INVERT)
	{
		g()->global.view_xview_aim = \
							g()->global.player->x - g()->view.view_wview / 2;
		g()->global.view_yview_aim = \
							g()->global.player->y - g()->view.view_hview / 2;
	}
}
