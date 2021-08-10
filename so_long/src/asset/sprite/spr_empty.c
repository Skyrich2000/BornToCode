/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:10:44 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:10:53 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_spr_empty(void)
{
	g()->asset.spr_empty = add_sprite(16, 32, 10, (t_box){0, 8, 32, 32});
	if (!add_sprite_subimage(g()->asset.spr_empty, "./res/png/empty_", 0, 0))
		return (ERROR);
	return (OK);
}
