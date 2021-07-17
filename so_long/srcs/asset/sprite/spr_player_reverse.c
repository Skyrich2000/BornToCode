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

static int	init_spr_player_die_reverse()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_die_right_reverse = add_sprite(0, 0, 7);
	game->asset.spr_player_die_left_reverse = add_sprite(0, 0, 7);
	if (!game->asset.spr_player_die_right_reverse || \
		!game->asset.spr_player_die_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_die_right_reverse, "./res/xpm_right/player_", 22, 18) || \
		!add_sprite_subimage(game->asset.spr_player_die_left_reverse, "./res/xpm_left/player_", 22, 18))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_attack_reverse()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_attack_right_reverse = add_sprite(0, 0, 7);
	game->asset.spr_player_attack_left_reverse = add_sprite(0, 0, 7);
	if (!game->asset.spr_player_attack_right_reverse || \
		!game->asset.spr_player_attack_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_attack_right_reverse, "./res/xpm_right/player_", 27, 23) || \
		!add_sprite_subimage(game->asset.spr_player_attack_left_reverse, "./res/xpm_left/player_", 27, 23))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_move_reverse()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_move_right_reverse = add_sprite(0, 0, 5);
	game->asset.spr_player_move_left_reverse = add_sprite(0, 0, 5);
	if (!game->asset.spr_player_move_right_reverse || \
		!game->asset.spr_player_move_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_move_right_reverse, "./res/xpm_right/player_", 14, 9) || \
		!add_sprite_subimage(game->asset.spr_player_move_left_reverse, "./res/xpm_left/player_", 14, 9))
		return (ERROR);
	return (OK);
}

static int	init_spr_player_idle_reverse()
{
	t_game	*game;

	game = g();
	game->asset.spr_player_idle_right_reverse = add_sprite(0, 0, 10);
	game->asset.spr_player_idle_left_reverse = add_sprite(0, 0, 10);
	if (!game->asset.spr_player_idle_right_reverse || \
		!game->asset.spr_player_idle_left_reverse)
		return (ERROR);
	if (!add_sprite_subimage(game->asset.spr_player_idle_right_reverse, "./res/xpm_right/player_", 8, 0) || \
		!add_sprite_subimage(game->asset.spr_player_idle_left_reverse, "./res/xpm_left/player_", 8, 0))
		return (ERROR);
	return (OK);
}

int			init_spr_player()
{
	return (init_spr_player_idle_reverse() && \
			init_spr_player_move_reverse() && \
			init_spr_player_attack_reverse() && \
			init_spr_player_die_reverse());
}
