/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:09:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

void	map_6(int *width, int *height)
{
	char	**map;
	int		out_dir[20];

	map = sl_split("\
1111111 \
1E10001 \
1010101 \
1Z0B0Z1 \
1C10101 \
1010Z01 \
1011011 \
10000P1 \
1111111", ' ');
	scr_build_map(map, width, height);
	sl_free_split(map);
	g()->scene->background = g()->asset.background_map_2;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;
	out_dir[SIG_MV_RIGHT] = SIG_MV_DOWN;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_LEFT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(5 * 32, 1 * 32, S_STRAIGHT, out_dir);
	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = SIG_MV_UP;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = SIG_MV_RIGHT;
	create_inverter_instance(1 * 32, 7 * 32, S_INVERT, out_dir);
}
