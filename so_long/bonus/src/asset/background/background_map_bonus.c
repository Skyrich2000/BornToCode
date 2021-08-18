/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:07:32 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

int	init_background_map(void)
{
	g()->asset.background_map_0 = \
			add_background("./res/png/background/background_0.png", -16, -32);
	g()->asset.background_map_1 = \
			add_background("./res/png/background/background_1.png", -16, -32);
	g()->asset.background_map_2 = \
			add_background("./res/png/background/background_2.png", -16, -32);
	return (OK);
}
