/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_gold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:09:51 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:10:30 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_spr_gold(void)
{
	g()->asset.spr_gold_red = \
								add_sprite(16, 32, 10, (t_box){8, 8, 24, 24});
	g()->asset.spr_gold_red_break = \
								add_sprite(16, 32, 10, (t_box){8, 8, 24, 24});
	if (!add_sprite_subimage(g()->asset.spr_gold_red, \
									"./res/png/gold_red/gold_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_gold_red_break, \
									"./res/png/gold_red/gold_", 1, 4))
		return (ERROR);
	return (OK);
}
