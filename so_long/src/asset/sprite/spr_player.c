/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 22:18:07 by ycha              #+#    #+#             */
/*   Updated: 2021/07/21 03:17:14 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

// 35 -> 13

static int	init_spr_player_die()
{
	t_game	*game;
	t_asset	*as;

	game = g();
	as = &game->asset;
	as->spr_player_die_right = add_sprite(27, 54, 7, (t_box){12, 35, 40, 54});
	as->spr_player_die_left = add_sprite(38, 54, 7, (t_box){23, 35, 51, 54});
	if (!as->spr_player_die_right || \
		!as->spr_player_die_left)
		return (ERROR);
	if (!add_sprite_subimage(as->spr_player_die_right, "./res/xpm_right/player_", 18, 22) || \
		!add_sprite_subimage(as->spr_player_die_left, "./res/xpm_left/player_", 18, 22))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_attack()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_attack_right = add_sprite(27, 54, 7, (t_box){12, 35, 64, 54});
	game->asset.spr_player_attack_left = add_sprite(38, 54, 7, (t_box){0, 35, 51, 54});
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
	game->asset.spr_player_move_right = add_sprite(27, 54, 5, (t_box){12, 35, 40, 54});
	game->asset.spr_player_move_left = add_sprite(38, 54, 5, (t_box){23, 35, 51, 54});
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
	game->asset.spr_player_idle_right = add_sprite(27, 54, 10, (t_box){12, 35, 40, 54});
	game->asset.spr_player_idle_left = add_sprite(38, 54, 10, (t_box){23, 35, 51, 54});
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
