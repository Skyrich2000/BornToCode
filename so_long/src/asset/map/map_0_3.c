/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 15:09:32 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	map_0_3(int *width, int *height)
{
	char	**map;
	int		out_dir[20];

	map = sl_split("\
1111111111111111 \
1E00000000000001 \
1111111111111101 \
100B00000000Z101 \
1004001111100101 \
1P0B00C1Z0000001 \
1111111111111111", ' ');
	scr_build_map(map, width, height);
	sl_free_split(map);
	g()->scene->background = g()->asset.background_map_2;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;
	g()->global.tutorial = 1;
	out_dir[SIG_MV_RIGHT] = SIG_MV_RIGHT;
	out_dir[SIG_MV_LEFT] = SIG_MV_LEFT;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(7 * 32, 3 * 32, S_STRAIGHT, out_dir);
	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_UP;
	out_dir[SIG_MV_DOWN] = SIG_MV_DOWN;
	create_inverter_instance(14 * 32, 3 * 32, S_INVERT, out_dir);
}
