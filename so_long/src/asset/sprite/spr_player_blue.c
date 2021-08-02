/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_player_blue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:18:07 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 02:59:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

// 35 -> 13

static int	init_spr_player_die()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_die_right = add_sprite(27, 54, 7, (t_box){20, 35, 40, 54});
	game->asset.spr_player_blue_die_left = add_sprite(30, 54, 7, (t_box){23, 35, 43, 54});
	if (!add_sprite_subimage(game->asset.spr_player_blue_die_right, "./res/png/player_blue_right/player_", 18, 22) || \
		!add_sprite_subimage(game->asset.spr_player_blue_die_left, "./res/png/player_blue_left/player_", 18, 22))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_attack()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_attack_right = add_sprite(27, 54, 7, (t_box){20, 35, 64, 54});
	game->asset.spr_player_blue_attack_left = add_sprite(30, 54, 7, (t_box){0, 35, 43, 54});
	if (!add_sprite_subimage(game->asset.spr_player_blue_attack_right, "./res/png/player_blue_right/player_", 23, 27) || \
		!add_sprite_subimage(game->asset.spr_player_blue_attack_left, "./res/png/player_blue_left/player_", 23, 27))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_move()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_move_right = add_sprite(27, 54, 5, (t_box){20, 35, 40, 54});
	game->asset.spr_player_blue_move_left = add_sprite(30, 54, 5, (t_box){23, 35, 43, 54});
	game->asset.spr_player_blue_move_right_reverse = add_sprite(27, 54, 5, (t_box){20, 35, 40, 54});
	game->asset.spr_player_blue_move_left_reverse = add_sprite(30, 54, 5, (t_box){23, 35, 43, 54});
	if (!add_sprite_subimage(game->asset.spr_player_blue_move_right, "./res/png/player_blue_right/player_", 9, 14) || \
		!add_sprite_subimage(game->asset.spr_player_blue_move_left, "./res/png/player_blue_left/player_", 9, 14) || \
		!add_sprite_subimage(game->asset.spr_player_blue_move_right_reverse, "./res/png/player_blue_right/player_", 14, 9) || \
		!add_sprite_subimage(game->asset.spr_player_blue_move_left_reverse, "./res/png/player_blue_left/player_", 14, 9))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_idle()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_idle_right = add_sprite(27, 54, 10, (t_box){20, 35, 40, 54});
	game->asset.spr_player_blue_idle_left = add_sprite(30, 54, 10, (t_box){23, 35, 43, 54});
	if (!add_sprite_subimage(game->asset.spr_player_blue_idle_right, "./res/png/player_blue_right/player_", 0, 8) || \
		!add_sprite_subimage(game->asset.spr_player_blue_idle_left, "./res/png/player_blue_left/player_", 0, 8))
		return (ERROR);
	return (OK);
}

int			init_spr_player_blue()
{
	return (init_spr_player_idle() && \
			init_spr_player_move() && \
			init_spr_player_attack() && \
			init_spr_player_die());
}
