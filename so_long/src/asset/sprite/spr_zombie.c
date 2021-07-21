/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_zombie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:18:07 by ycha              #+#    #+#             */
/*   Updated: 2021/07/21 05:08:09 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	init_spr_zombie_die()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_die_right_reverse = add_sprite(32, 64, 5, (t_box){ 19, 35, 49, 64 });
	game->asset.spr_zombie_die_left_reverse = add_sprite(32, 64, 5, (t_box){ 14, 35, 44, 64 });
	if (!game->asset.spr_zombie_die_right_reverse || \
		!game->asset.spr_zombie_die_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_zombie_die_right_reverse, "./res/xpm/zombie_right/zombie_", 23, 13) || \
		!add_sprite_subimage(game->asset.spr_zombie_die_left_reverse, "./res/xpm/zombie_left/zombie_", 23, 13))
		return (ERROR);
	return (OK);
}

static int	init_spr_zombie_idle()
{
	t_game *game;

	game = g();
	game->asset.spr_zombie_idle_right_reverse = add_sprite(32, 64, 10, (t_box){ 19, 35, 49, 64 });
	game->asset.spr_zombie_idle_left_reverse = add_sprite(32, 64, 10, (t_box){ 14, 35, 44, 64 });
	if (!game->asset.spr_zombie_idle_right_reverse || \
		!game->asset.spr_zombie_idle_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_zombie_idle_right_reverse, "./res/xpm/zombie_right/zombie_", 1, 0) || \
		!add_sprite_subimage(game->asset.spr_zombie_idle_left_reverse, "./res/xpm/zombie_left/zombie_", 1, 0))
		return (ERROR);
	return (OK);
}

int			init_spr_zombie()
{
	return (init_spr_zombie_idle() && \
			init_spr_zombie_die());
}
