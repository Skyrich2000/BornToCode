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

int		init_asset()
{
	return (init_background_black() && \
			init_spr_player() && \
			init_spr_zombie() && \
			init_scene_play());
}

void	free_asset()
{
	delete_sprite(g()->asset.spr_player_idle_right);
	delete_sprite(g()->asset.spr_player_move_right);
	free(g()->asset.background_black);
}
