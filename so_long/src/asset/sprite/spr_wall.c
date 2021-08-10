/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 15:58:45 by su                #+#    #+#             */
/*   Updated: 2021/08/10 15:59:31 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
