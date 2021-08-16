/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_gold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:14:18 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:14:19 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

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
