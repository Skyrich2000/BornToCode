/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:14:08 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:14:10 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

int	init_spr_exit(void)
{
	g()->asset.spr_exit = add_sprite(16, 32, 10, (t_box){14, 14, 18, 22});
	if (!add_sprite_subimage(g()->asset.spr_exit, "./res/png/exit/exit_", 0, 0))
		return (ERROR);
	return (OK);
}
