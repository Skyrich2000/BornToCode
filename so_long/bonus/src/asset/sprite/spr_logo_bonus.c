/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_logo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:14:43 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:14:46 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

int	init_spr_logo(void)
{
	g()->asset.spr_logo = \
						add_sprite(500 / 2, 116 / 2, 10, (t_box){0, 0, 0, 0});
	if (!add_sprite_subimage(g()->asset.spr_logo, "./res/png/logo/logo_", 3, 3))
		return (ERROR);
	return (OK);
}
