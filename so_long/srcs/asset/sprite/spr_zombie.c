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

static int	init_spr_zombie_die()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_die_right = add_sprite(0, 0, 7);
	game->asset.spr_zombie_die_left = add_sprite(0, 0, 7);
	if (!game->asset.spr_zombie_die_right || \
		!game->asset.spr_zombie_die_left)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_zombie_die_right, "./res/xpm_right/zombie_", 2, 5) || \
		!add_sprite_subimage(game->asset.spr_zombie_die_left, "./res/xpm_left/zombie_", 2, 5))
		return (ERROR);
	return (OK);
}

static int	init_spr_zombie_idle()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_idle_right = add_sprite(0, 0, 10);
	game->asset.spr_zombie_idle_left = add_sprite(0, 0, 10);
	if (!game->asset.spr_zombie_idle_right || \
		!game->asset.spr_zombie_idle_left)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_zombie_idle_right, "./res/xpm_right/zombie_", 0, 1) || \
		!add_sprite_subimage(game->asset.spr_zombie_idle_left, "./res/xpm_left/zombie_", 0, 1))
		return (ERROR);
	return (OK);
}

int			init_spr_zombie()
{
	return (init_spr_zombie_idle() && \
			init_spr_zombie_die());
}
