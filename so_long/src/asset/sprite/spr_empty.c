/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_empty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:14:01 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:14:03 by ycha             ###   ########.fr       */
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
