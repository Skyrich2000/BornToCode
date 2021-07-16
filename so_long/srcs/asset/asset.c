/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/07/16 07:48:51 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

void	init_asset()
{
	t_game *game;

	game = g();
	game->asset.spr_player_idle_right = add_sprite(0, 0, 10);
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_8.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_7.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_6.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_5.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_4.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_3.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_2.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_1.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_right, "./res/xpm/player_0.xpm");

	game->asset.spr_player_idle_left = add_sprite(0, 0, 10);
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_8.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_7.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_6.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_5.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_4.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_3.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_2.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_1.xpm");
	add_sprite_subimage(game->asset.spr_player_idle_left, "./res/xpm_reverse/player_0.xpm");

	game->asset.spr_player_move_right = add_sprite(0, 0, 5);
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_14.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_13.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_12.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_11.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_10.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_9.xpm");

	game->asset.spr_player_move_left = add_sprite(0, 0, 5);
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm_reverse/player_14.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm_reverse/player_13.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm_reverse/player_12.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm_reverse/player_11.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm_reverse/player_10.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm_reverse/player_9.xpm");

	game->asset.spr_player_attack_right = add_sprite(0, 0, 7);
	add_sprite_subimage(game->asset.spr_player_attack_right, "./res/xpm/player_27.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_right, "./res/xpm/player_26.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_right, "./res/xpm/player_25.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_right, "./res/xpm/player_24.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_right, "./res/xpm/player_23.xpm");

	game->asset.spr_player_attack_left = add_sprite(0, 0, 7);
	add_sprite_subimage(game->asset.spr_player_attack_left, "./res/xpm_reverse/player_27.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_left, "./res/xpm_reverse/player_26.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_left, "./res/xpm_reverse/player_25.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_left, "./res/xpm_reverse/player_24.xpm");
	add_sprite_subimage(game->asset.spr_player_attack_left, "./res/xpm_reverse/player_23.xpm");

	game->asset.spr_zombie_move_left = add_sprite(0, 0, 5);
	add_sprite_subimage(game->asset.spr_zombie_move_left, "./res/xpm/zombie_5.xpm");
	add_sprite_subimage(game->asset.spr_zombie_move_left, "./res/xpm/zombie_4.xpm");
	add_sprite_subimage(game->asset.spr_zombie_move_left, "./res/xpm/zombie_3.xpm");
	add_sprite_subimage(game->asset.spr_zombie_move_left, "./res/xpm/zombie_2.xpm");
}
