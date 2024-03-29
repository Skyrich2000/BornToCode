/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:09:20 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

void	map_3(int *width, int *height)
{
	char	**map;
	int		out_dir[20];

	map = sl_split("\
11111111111 \
10000P00001 \
10111011101 \
101000001C1 \
10B011100Z1 \
101000001E1 \
11111111111", ' ');
	scr_build_map(map, width, height);
	sl_free_split(map);
	g()->scene->background = g()->asset.background_map_1;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;
	out_dir[SIG_MV_RIGHT] = SIG_MV_DOWN;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_LEFT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(9 * 32, 1 * 32, S_STRAIGHT, out_dir);
	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = SIG_MV_DOWN;
	out_dir[SIG_MV_UP] = SIG_MV_RIGHT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(1 * 32, 1 * 32, S_INVERT, out_dir);
}
