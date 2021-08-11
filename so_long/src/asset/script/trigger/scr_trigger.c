/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_trigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:17:20 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:17:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_trigger(t_instance *trigger)
{
	trigger->obj.trigger.target->signal = trigger->obj.trigger.signal;
	destroy_instance(trigger);
}
