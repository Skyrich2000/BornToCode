/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_zombie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:18:07 by ycha              #+#    #+#             */
/*   Updated: 2021/07/21 00:39:55 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	init_spr_zombie_die()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_die_right = add_sprite(31, 64, 15, (t_box){ 14, 35, 44, 64 });
	game->asset.spr_zombie_die_left = add_sprite(31, 64, 15, (t_box){ 14, 35, 44, 64 });
	if (!game->asset.spr_zombie_die_right || \
		!game->asset.spr_zombie_die_left)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_zombie_die_right, "./res/xpm_right/zombie_", 13, 23) || \
		!add_sprite_subimage(game->asset.spr_zombie_die_left, "./res/xpm_left/zombie_", 13, 23))
		return (ERROR);
	return (OK);
}

static int	init_spr_zombie_idle()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_idle_right = add_sprite(31, 64, 10, (t_box){ 14, 35, 44, 64 });
	game->asset.spr_zombie_idle_left = add_sprite(31, 64, 10, (t_box){ 14, 35, 44, 64 });
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
