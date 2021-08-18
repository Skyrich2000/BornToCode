/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:14:52 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:14:53 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

int	init_spr_plane(void)
{
	g()->asset.spr_plane = add_sprite(32, 32, 10, (t_box){0, 0, 32, 32});
	if (!add_sprite_subimage(g()->asset.spr_plane, \
											"./res/png/plane/plane_", 3, 3))
		return (ERROR);
	return (OK);
}
