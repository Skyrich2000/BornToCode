/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 17:26:05 by su                #+#    #+#             */
/*   Updated: 2021/08/10 17:26:08 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance	*create_wait_instance(int x, int y)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_empty, (int [3]){WAIT, x, y}, 0, 0);
	return (ins);
}
