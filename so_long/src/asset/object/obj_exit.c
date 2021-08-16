/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:09:56 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:09:58 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

t_instance	*create_exit_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_exit, \
						(int [3]){EXIT, x, y}, 0, draw_self);
	return (ins);
}
