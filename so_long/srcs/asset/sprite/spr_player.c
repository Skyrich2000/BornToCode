/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:18:07 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 22:18:10 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

static int	init_spr_player_die()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_die_right = add_sprite(0, 0, 7);
	game->asset.spr_player_die_left = add_sprite(0, 0, 7);
	if (!game->asset.spr_player_die_right || \
		!game->asset.spr_player_die_left)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_die_right, "./res/xpm_right/player_", 18, 22) || \
		!add_sprite_subimage(game->asset.spr_player_die_left, "./res/xpm_left/player_", 18, 22))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_attack()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_attack_right = add_sprite(0, 0, 7);
	game->asset.spr_player_attack_left = add_sprite(0, 0, 7);
	if (!game->asset.spr_player_attack_right || \
		!game->asset.spr_player_attack_left)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_attack_right, "./res/xpm_right/player_", 23, 27) || \
		!add_sprite_subimage(game->asset.spr_player_attack_left, "./res/xpm_left/player_", 23, 27))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_move()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_move_right = add_sprite(0, 0, 5);
	game->asset.spr_player_move_left = add_sprite(0, 0, 5);
	if (!game->asset.spr_player_move_right || \
		!game->asset.spr_player_move_left)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm_right/player_", 9, 14) || \
		!add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm_left/player_", 9, 14))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_idle()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_idle_right = add_sprite(0, 0, 10);
	game->asset.spr_player_idle_left = add_sprite(0, 0, 10);
	if (!game->asset.spr_player_idle_right || \
		!game->asset.spr_player_idle_left)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm_right/player_", 0, 8) || \
		!add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_left/player_", 0, 8))
		return (ERROR);
	return (OK);
}

int			init_spr_player()
{
	return (init_spr_player_idle() && \
			init_spr_player_move() && \
			init_spr_player_attack() && \
			init_spr_player_die());
}
