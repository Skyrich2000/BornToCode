/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/07/24 16:17:40 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

int		init_asset()
{
	return (init_background_map1() && \
			init_font_default() && \
			init_spr_player_red() && \
			init_spr_player_blue() && \
			init_spr_zombie() && \
			init_spr_empty() && \
			init_spr_wall() && \
			init_spr_box() && \
			init_spr_gold() && \
			init_spr_inverter() && \
			init_spr_exit() && \
			init_scene_play());
}

void	free_asset()
{
	// // delete_sprite(g()->asset.spr_player_idle_right);
	// delete_sprite(g()->asset.spr_player_move_right);
	//free(g()->asset.background_black);
}
