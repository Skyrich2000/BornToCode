/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:59:46 by ycha              #+#    #+#             */
/*   Updated: 2021/08/13 23:13:59 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philosopher *philo)
{
	display_message(philo, MSG_THINKING);
	while (1)
	{
		if (get_value(&philo->res->forks[philo->fork_index[LEFT]]) == 0 && \
			get_value(&philo->res->forks[philo->fork_index[RIGHT]]) == 0)
			break ;
	}
}

static void	eating(t_philosopher *philo)
{
	set_value(&philo->res->forks[philo->fork_index[LEFT]], 1);
	display_message(philo, MSG_TAKE_FORK);
	set_value(&philo->res->forks[philo->fork_index[RIGHT]], 1);
	display_message(philo, MSG_TAKE_FORK);
	set_value(&philo->eat_count, get_value(&philo->eat_count) + 1);
	display_message(philo, MSG_EATING);
	psleep(philo->res, get_time() + philo->arg->time_to_eat);
	set_value(&philo->res->forks[philo->fork_index[LEFT]], 0);
	set_value(&philo->res->forks[philo->fork_index[RIGHT]], 0);
	set_value(&philo->die_time, \
						get_value(&philo->die_time) + philo->arg->time_to_die);
}

static void	sleeping(t_philosopher *philo)
{
	display_message(philo, MSG_SLEEPING);
	psleep(philo->res, get_time() + philo->arg->time_to_sleep);
}

void	*philosopher(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	while (!get_value(&philo->res->end))
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (0);
}
