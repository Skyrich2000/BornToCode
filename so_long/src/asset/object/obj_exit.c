/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:23:09 by su                #+#    #+#             */
/*   Updated: 2021/08/10 17:23:11 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance	*create_exit_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_exit, \
						(int [3]){EXIT, x, y}, 0, draw_self);
	return (ins);
}
