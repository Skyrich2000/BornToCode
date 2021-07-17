/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_zombie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:18:07 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 22:18:10 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	init_spr_zombie_die_reverse()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_die_right_reverse = add_sprite(0, 0, 7);
	game->asset.spr_zombie_die_left_reverse = add_sprite(0, 0, 7);
	if (!!game->asset.spr_zombie_die_right_reverse || \
		!game->asset.spr_zombie_die_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_zombie_die_right_reverse, "./res/xpm_right/zombie_", 5, 2) || \
		!add_sprite_subimage(game->asset.spr_zombie_die_left_reverse, "./res/xpm_left/zombie_", 5, 2))
		return (ERROR);
	return (OK);
}

static int	init_spr_zombie_idle_reverse()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_idle_right_reverse = add_sprite(0, 0, 20);
	game->asset.spr_zombie_idle_left_reverse = add_sprite(0, 0, 20);
	if (!game->asset.spr_zombie_idle_right_reverse || \
		!game->asset.spr_zombie_idle_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_zombie_idle_right_reverse, "./res/xpm_right/zombie_", 1, 0) || \
		!add_sprite_subimage(game->asset.spr_zombie_idle_left_reverse, "./res/xpm_left/zombie_", 1, 0))
		return (ERROR);
	return (OK);
}

int			init_spr_zombie()
{
	return (init_spr_zombie_idle_reverse() && \
			init_spr_zombie_die_reverse());
}
