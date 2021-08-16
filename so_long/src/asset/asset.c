/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:07:04 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:07:06 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

int	init_asset(void)
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
			init_spr_state() && \
			init_scene_main() && \
			init_scene_nick() && \
			init_scene_play() && \
			init_scene_rank());
}
