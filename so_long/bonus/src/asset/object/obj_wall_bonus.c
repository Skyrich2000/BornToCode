/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:12:45 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:12:48 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

t_instance	*create_wall_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_wall, \
									(int [3]){WALL, x, y}, 0, draw_self);
	create_wall_up_instance(x, y);
	return (ins);
}

t_instance	*create_wall_up_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_wall_up, \
									(int [3]){WALL_UP, x, y}, 0, draw_self);
	return (ins);
}

t_instance	*create_wall_inv_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_empty, \
									(int [3]){WALL_INV, x, y}, 0, draw_self);
	return (ins);
}
