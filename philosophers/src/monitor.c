/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:59:46 by ycha              #+#    #+#             */
/*   Updated: 2021/08/14 05:57:20 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_dead(t_monitor *self)
{
	int	i;

	i = -1;
	while (++i < self->arg->number)
	{
		if (get_value(&self->philos[i].die_time) < get_time())
		{
			display_message(&self->philos[i], MSG_DEAD);
			set_value(&self->res->end, 1);
			return (TRUE);
		}
	}
	return (FALSE);
}

static int	is_all_ate(t_monitor *self)
{
	int	i;

	i = -1;
	if (self->arg->must_eat_count == -1)
		return (FALSE);
	while (++i < self->arg->number)
	{
		if (get_value(&self->philos[i].eat_count) < self->arg->must_eat_count)
			return (FALSE);
	}
	display_message(&self->philos[0], MSG_ENOUGH);
	set_value(&self->res->end, 1);
	return (TRUE);
}

void	*monitor(void *data)
{
	t_monitor	*self;

	self = (t_monitor *)data;
	while (1)
	{
		if (is_dead(self))
			return (0);
		if (is_all_ate(self))
			return (0);
		usleep(10);
	}
	return (0);
}
