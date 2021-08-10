/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_zombie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:18:07 by ycha              #+#    #+#             */
/*   Updated: 2021/08/10 16:08:12 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	init_spr_zombie_die(void)
{
	t_game	*game;

	game = g();
	game->asset.spr_zombie_blue_die_right_reverse = \
							add_sprite(32, 64, 5, (t_box){19, 35, 49, 64});
	game->asset.spr_zombie_blue_die_left_reverse = \
							add_sprite(32, 64, 5, (t_box){14, 35, 44, 64});
	if (!add_sprite_subimage(game->asset.spr_zombie_blue_die_right_reverse, \
							"./res/png/zombie_right/zombie_", 24, 13) || \
		!add_sprite_subimage(game->asset.spr_zombie_blue_die_left_reverse, \
							"./res/png/zombie_left/zombie_", 24, 13))
		return (ERROR);
	return (OK);
}

static int	init_spr_zombie_idle(void)
{
	t_game	*game;

	game = g();
	game->asset.spr_zombie_blue_idle_right_reverse = \
							add_sprite(32, 64, 10, (t_box){19, 35, 49, 64});
	game->asset.spr_zombie_blue_idle_left_reverse = \
							add_sprite(32, 64, 10, (t_box){14, 35, 44, 64});
	if (!add_sprite_subimage(game->asset.spr_zombie_blue_idle_right_reverse, \
							"./res/png/zombie_right/zombie_", 1, 0) || \
		!add_sprite_subimage(game->asset.spr_zombie_blue_idle_left_reverse, \
							"./res/png/zombie_left/zombie_", 1, 0))
		return (ERROR);
	return (OK);
}

int	init_spr_zombie(void)
{
	return (init_spr_zombie_idle() && \
			init_spr_zombie_die());
}
