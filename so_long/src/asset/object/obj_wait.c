/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:12:37 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:12:39 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

t_instance	*create_wait_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_empty, (int [3]){WAIT, x, y}, 0, 0);
	return (ins);
}
