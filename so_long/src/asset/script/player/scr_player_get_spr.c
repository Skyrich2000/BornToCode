/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_get_spr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:36:09 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:36:11 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

t_sprite	*scr_player_get_spr(int type, int inverted, int dir)
{
	int			idx;
	void		*asset;
	t_sprite	*spr;

	idx = (inverted == S_STRAIGHT) * 10 + type * 2 + (dir != 1);
	asset = &(g()->asset);
	spr = *(t_sprite **)(asset + sizeof(void *) * idx);
	return (spr);
}
