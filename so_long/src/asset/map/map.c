/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:08:20 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

int	init_map(void)
{
	g()->asset.maps[0] = map_0_0;
	g()->asset.maps[1] = map_0_1;
	g()->asset.maps[2] = map_0_2;
	g()->asset.maps[3] = map_0_3;
	g()->asset.maps[4] = map_0_4;
	g()->asset.maps[5] = map_0_5;
	g()->asset.maps[6] = map_1;
	g()->asset.maps[7] = map_2;
	g()->asset.maps[8] = map_3;
	g()->asset.maps[9] = map_4;
	g()->asset.maps[10] = map_5;
	return (OK);
}
