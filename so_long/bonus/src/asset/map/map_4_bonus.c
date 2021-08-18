/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:09:23 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

void	map_4(int *width, int *height)
{
	int		out_dir[20];
	char	**map;

	map = sl_split("\
11111111111111 \
1P0C00C0000001 \
10111111110101 \
10BZBZBZE10001 \
10111111110101 \
10C0C000000001 \
11111111111111", ' ');
	scr_build_map(map, width, height);
	sl_free_split(map);
	g()->scene->background = g()->asset.background_map_1;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;
	out_dir[SIG_MV_RIGHT] = SIG_MV_UP;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = SIG_MV_LEFT;
	create_inverter_instance(12 * 32, 5 * 32, S_STRAIGHT, out_dir);
	out_dir[SIG_MV_RIGHT] = SIG_MV_DOWN;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_LEFT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(12 * 32, 1 * 32, S_INVERT, out_dir);
}
