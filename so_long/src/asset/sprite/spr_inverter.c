/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_inverter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:14:28 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:14:29 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_spr_inverter(void)
{
	g()->asset.spr_inverter_idle = \
								add_sprite(16, 32, 50, (t_box){14, 14, 18, 22});
	g()->asset.spr_inverter_blue = \
								add_sprite(16, 32, 10, (t_box){14, 14, 18, 22});
	g()->asset.spr_inverter_red = \
								add_sprite(16, 32, 10, (t_box){14, 14, 18, 22});
	if (!add_sprite_subimage(g()->asset.spr_inverter_idle, \
								"./res/png/inverter/inverter_idle_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_inverter_blue, \
								"./res/png/inverter/inverter_blue_", 0, 5) || \
		!add_sprite_subimage(g()->asset.spr_inverter_red, \
								"./res/png/inverter/inverter_red_", 0, 5))
		return (ERROR);
	return (OK);
}
