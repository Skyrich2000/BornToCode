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

static int	is_dead(t_arg *arg, t_philosopher *philos, t_data *end)
{
	int	i;

	i = -1;
	while (++i < arg->number)
	{
		if (get_value(&philos[i].die_time) < get_time())
		{
			display_message(&philos[i], MSG_DEAD);
			set_value(end, 1);
			return (TRUE);
		}
	}
	return (FALSE);
}

static int	is_all_eaten(t_arg *arg, t_philosopher *philos, t_data *end)
{
	int	i;

	i = -1;
	if (arg->must_eat_count == -1)
		return (FALSE);
	while (++i < arg->number)
	{
		if (get_value(&philos[i].eat_count) < arg->must_eat_count)
			return (FALSE);
	}
	display_message(&philos[0], MSG_ENOUGH);
	set_value(end, 1);
	return (TRUE);
}

void	monitoring(t_arg *arg, t_philosopher *philos, t_data *end)
{
	while (1)
	{
		if (is_dead(arg, philos, end))
			return ;
		if (is_all_eaten(arg, philos, end))
			return ;
		usleep(500);
	}
}
