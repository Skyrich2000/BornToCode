/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:14:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:14:37 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

int	init_spr_light(void)
{
	g()->asset.spr_light = add_sprite(500, 500, 10, (t_box){0, 0, 0, 0});
	g()->asset.spr_light_5 = add_sprite(500, 500, 10, (t_box){0, 0, 0, 0});
	if (!add_sprite_subimage(g()->asset.spr_light, \
											"./res/png/light/light_", 3, 3) || \
		!add_sprite_subimage(g()->asset.spr_light_5, \
												"./res/png/light/light_", 2, 2))
		return (ERROR);
	return (OK);
}
