/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/07/28 05:11:56 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

int		init_asset()
{
	return (init_background_main() && \
			init_background_nick() && \
			init_background_rank() && \
			init_background_map() && \
			init_font_su() && \
			init_font_fat() && \
			init_map() && \
			init_spr_player_red() && \
			init_spr_player_blue() && \
			init_spr_zombie() && \
			init_spr_empty() && \
			init_spr_light() && \
			init_spr_wall() && \
			init_spr_box() && \
			init_spr_gold() && \
			init_spr_inverter() && \
			init_spr_exit() && \
			init_spr_plane() && \
			init_spr_logo() && \
			init_scene_main() && \
			init_scene_nick() && \
			init_scene_play() && \
			init_scene_rank());
}

void	free_asset()
{
	//free_list(g()->asset.spr_player_blue_attack_left->imgs, 0);
	//free(g()->asset.spr_player_blue_attack_left);
}
