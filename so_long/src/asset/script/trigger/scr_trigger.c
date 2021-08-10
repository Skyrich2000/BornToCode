/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_trigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:35:31 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:35:34 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_trigger(t_instance *trigger)
{
	trigger->obj.trigger.target->signal = trigger->obj.trigger.signal;
	destroy_instance(trigger);
}
