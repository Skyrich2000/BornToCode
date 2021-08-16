/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_player_blue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:15:02 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:15:07 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

static int	init_spr_player_die(void)
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_die_right = \
								add_sprite(27, 50, 7, (t_box){17, 30, 37, 50});
	game->asset.spr_player_blue_die_left = \
								add_sprite(36, 50, 7, (t_box){26, 30, 46, 50});
	if (!add_sprite_subimage(game->asset.spr_player_blue_die_right, \
							"./res/png/player_blue_right/player_", 18, 22) || \
		!add_sprite_subimage(game->asset.spr_player_blue_die_left, \
							"./res/png/player_blue_left/player_", 18, 22))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_attack(void)
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_attack_right = \
								add_sprite(27, 50, 7, (t_box){17, 30, 64, 50});
	game->asset.spr_player_blue_attack_left = \
								add_sprite(36, 50, 7, (t_box){0, 30, 46, 50});
	if (!add_sprite_subimage(game->asset.spr_player_blue_attack_right, \
							"./res/png/player_blue_right/player_", 23, 27) || \
		!add_sprite_subimage(game->asset.spr_player_blue_attack_left, \
							"./res/png/player_blue_left/player_", 23, 27))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_move(void)
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_move_right = \
								add_sprite(27, 50, 5, (t_box){17, 30, 37, 50});
	game->asset.spr_player_blue_move_left = \
								add_sprite(36, 50, 5, (t_box){26, 30, 46, 50});
	game->asset.spr_player_blue_move_right_reverse = \
								add_sprite(27, 50, 5, (t_box){17, 30, 37, 50});
	game->asset.spr_player_blue_move_left_reverse = \
								add_sprite(36, 50, 5, (t_box){26, 30, 46, 50});
	if (!add_sprite_subimage(game->asset.spr_player_blue_move_right, \
							"./res/png/player_blue_right/player_", 9, 14) || \
		!add_sprite_subimage(game->asset.spr_player_blue_move_left, \
							"./res/png/player_blue_left/player_", 9, 14) || \
		!add_sprite_subimage(game->asset.spr_player_blue_move_right_reverse, \
							"./res/png/player_blue_right/player_", 14, 9) || \
		!add_sprite_subimage(game->asset.spr_player_blue_move_left_reverse, \
							"./res/png/player_blue_left/player_", 14, 9))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_idle(void)
{
	t_game	*game;

	game = g();
	game->asset.spr_player_blue_idle_right = \
								add_sprite(27, 50, 10, (t_box){17, 30, 37, 50});
	game->asset.spr_player_blue_idle_left = \
								add_sprite(36, 50, 10, (t_box){26, 30, 46, 50});
	if (!add_sprite_subimage(game->asset.spr_player_blue_idle_right, \
							"./res/png/player_blue_right/player_", 0, 8) || \
		!add_sprite_subimage(game->asset.spr_player_blue_idle_left, \
							"./res/png/player_blue_left/player_", 0, 8))
		return (ERROR);
	return (OK);
}

int	init_spr_player_blue(void)
{
	return (init_spr_player_idle() && \
			init_spr_player_move() && \
			init_spr_player_attack() && \
			init_spr_player_die());
}
