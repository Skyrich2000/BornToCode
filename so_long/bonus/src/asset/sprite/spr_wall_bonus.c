/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:15:31 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:15:32 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

int	init_spr_wall(void)
{
	g()->asset.spr_wall = add_sprite(16, 32, 10, (t_box){0, 8, 32, 32});
	g()->asset.spr_wall_up = add_sprite(16, 32, 10, (t_box){0, 8, 32, 32});
	if (!add_sprite_subimage(g()->asset.spr_wall, "./res/png/wall/wall_", 0, 0) \
	|| !add_sprite_subimage(g()->asset.spr_wall_up, \
		"./res/png/wall/wall_up_", 0, 0))
		return (ERROR);
	return (OK);
}
