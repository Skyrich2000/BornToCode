/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/07/20 15:41:39 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

int		init_asset()
{
	return (init_background_black() && \
			init_spr_player() && \
			init_spr_zombie() && \
			init_spr_empty() && \
			init_scene_play());
}

void	free_asset()
{
	delete_sprite(g()->asset.spr_player_idle_right);
	delete_sprite(g()->asset.spr_player_move_right);
	free(g()->asset.background_black);
}
