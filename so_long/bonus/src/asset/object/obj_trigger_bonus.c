/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_trigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:12:28 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:12:29 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

t_instance	*create_trigger_instance(int pos[2], int inverted, \
												t_instance *target, int signal)
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_empty, \
									(int [3]){TRIGGER, pos[0], pos[1]}, 0, 0);
	ins->obj.trigger.target = target;
	ins->obj.trigger.signal = signal;
	ins->obj.trigger.inverted = inverted;
	return (ins);
}
