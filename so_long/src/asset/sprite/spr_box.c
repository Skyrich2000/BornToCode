/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_box.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:05:45 by suhshin           #+#    #+#             */
/*   Updated: 2021/08/10 16:12:15 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_spr_box(void)
{
	g()->asset.spr_box_red = \
						add_sprite(16, 32, 10, (t_box){0, 0, 32, 32});
	g()->asset.spr_box_blue = \
						add_sprite(16, 32, 6, (t_box){0, 0, 32, 32});
	g()->asset.spr_box_red_break = \
						add_sprite(16, 32, 6, (t_box){0, 0, 32, 32});
	if (!add_sprite_subimage(g()->asset.spr_box_red, \
										"./res/png/box_red/box_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_box_blue, \
										"./res/png/box_blue/box_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_box_red_break, \
										"./res/png/box_red/box_", 1, 4))
		return (ERROR);
	return (OK);
}
