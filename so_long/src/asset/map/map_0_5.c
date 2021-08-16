/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_0_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:09:07 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

void	map_0_5(int *width, int *height)
{
	char	**map;
	int		out_dir[20];

	map = sl_split("\
111111111111 \
1P10000101E1 \
101011011101 \
101000000001 \
101111011111 \
10111100Z0C1 \
10000000Z0C1 \
111111111111", ' ');
	scr_build_map(map, width, height);
	sl_free_split(map);
	g()->scene->background = g()->asset.background_map_2;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;
	g()->global.tutorial = 1;
	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = SIG_MV_UP;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = SIG_MV_RIGHT;
	create_inverter_instance(3 * 32, 3 * 32, S_STRAIGHT, out_dir);
	out_dir[SIG_MV_RIGHT] = SIG_MV_UP;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = SIG_MV_LEFT;
	create_inverter_instance(10 * 32, 3 * 32, S_INVERT, out_dir);
}
