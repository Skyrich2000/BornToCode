/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_logo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:08:22 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:12:42 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_spr_logo(void)
{
	g()->asset.spr_logo = \
						add_sprite(500 / 2, 116 / 2, 10, (t_box){0, 0, 0, 0});
	if (!add_sprite_subimage(g()->asset.spr_logo, "./res/png/logo/logo_", 3, 3))
		return (ERROR);
	return (OK);
}
