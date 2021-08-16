/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:05:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:05:46 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_H
# define ASSET_H
# include "engine/engine.h"
# include "asset/background.h"
# include "asset/font.h"
# include "asset/global.h"
# include "asset/map.h"
# include "asset/object.h"
# include "asset/scene.h"
# include "asset/script.h"
# include "asset/sprite.h"

typedef struct s_asset
{
	t_sprite		*spr_player_blue_idle_right;
	t_sprite		*spr_player_blue_idle_left;
	t_sprite		*spr_player_blue_move_right;
	t_sprite		*spr_player_blue_move_left;
	t_sprite		*spr_player_blue_move_right_reverse;
	t_sprite		*spr_player_blue_move_left_reverse;
	t_sprite		*spr_player_blue_attack_right;
	t_sprite		*spr_player_blue_attack_left;
	t_sprite		*spr_player_blue_die_right;
	t_sprite		*spr_player_blue_die_left;

	t_sprite		*spr_player_red_idle_right;
	t_sprite		*spr_player_red_idle_left;
	t_sprite		*spr_player_red_move_right;
	t_sprite		*spr_player_red_move_left;
	t_sprite		*spr_player_red_move_right_reverse;
	t_sprite		*spr_player_red_move_left_reverse;
	t_sprite		*spr_player_red_attack_right;
	t_sprite		*spr_player_red_attack_left;
	t_sprite		*spr_player_red_die_right;
	t_sprite		*spr_player_red_die_left;

	t_sprite		*spr_zombie_blue_idle_right_reverse;
	t_sprite		*spr_zombie_blue_idle_left_reverse;
	t_sprite		*spr_zombie_blue_die_right_reverse;
	t_sprite		*spr_zombie_blue_die_left_reverse;

	t_sprite		*spr_light;
	t_sprite		*spr_light_5;

	t_sprite		*spr_empty;
	t_sprite		*spr_wall;
	t_sprite		*spr_wall_up;

	t_sprite		*spr_box_red;
	t_sprite		*spr_box_blue;
	t_sprite		*spr_box_red_break;

	t_sprite		*spr_gold_red;
	t_sprite		*spr_gold_red_break;

	t_sprite		*spr_inverter_idle;
	t_sprite		*spr_inverter_red;
	t_sprite		*spr_inverter_blue;

	t_sprite		*spr_exit;
	t_sprite		*spr_plane;
	t_sprite		*spr_logo;

	t_sprite		*spr_ready;
	t_sprite		*spr_straight;
	t_sprite		*spr_invert;
	t_sprite		*spr_clear;
	t_sprite		*spr_gameover;

	t_scene			*scene_main;
	t_scene			*scene_nick;
	t_scene			*scene_play;
	t_scene			*scene_rank;

	t_font			*font_su;
	t_font			*font_fat_xsmall;
	t_font			*font_fat_small;
	t_font			*font_fat_big;

	t_background	*background_main;
	t_background	*background_nick;
	t_background	*background_rank;
	t_background	*background_map_0;
	t_background	*background_map_1;
	t_background	*background_map_2;

	void			(*maps[MAP_SIZE])(int *w, int *h);
}	t_asset;

int			init_asset(void);

#endif
