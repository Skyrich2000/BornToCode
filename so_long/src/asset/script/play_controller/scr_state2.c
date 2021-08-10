/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_state2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:47:14 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:47:31 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_state_clear(void)
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 3)
	{
		g()->global.map_index++;
		if (!g()->global.tutorial)
			g()->global.time_all_lv += g()->global.time;
		if (g()->global.map_index >= MAP_SIZE)
		{
			scr_save_rank(g()->global.nick, \
						g()->global.time_all_lv, g()->global.deathcount);
			scene_change(g()->asset.scene_rank);
		}
		else
		{
			scene_restart();
		}
	}
}

void	scr_state_gameover(void)
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 4)
		scene_restart();
}
