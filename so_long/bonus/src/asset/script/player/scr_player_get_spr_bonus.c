/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_get_spr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:25:37 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:25:38 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

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
