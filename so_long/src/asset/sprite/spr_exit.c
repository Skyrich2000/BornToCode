/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spr_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:10:33 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:12:37 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_spr_exit(void)
{
	g()->asset.spr_exit = add_sprite(16, 32, 10, (t_box){14, 14, 18, 22});
	if (!add_sprite_subimage(g()->asset.spr_exit, "./res/png/exit/exit_", 0, 0))
		return (ERROR);
	return (OK);
}
