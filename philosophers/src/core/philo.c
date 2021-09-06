/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:59:46 by ycha              #+#    #+#             */
/*   Updated: 2021/08/14 05:57:23 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pickup(t_philosopher *philo)
{
	int	flag;

	flag = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->res->forks[philo->fork_index[LEFT]].lock);
		pthread_mutex_lock(&philo->res->forks[philo->fork_index[RIGHT]].lock);
		if (philo->res->forks[philo->fork_index[LEFT]].value == 0 && \
			philo->res->forks[philo->fork_index[RIGHT]].value == 0)
		{
			philo->res->forks[philo->fork_index[LEFT]].value = 1;
			philo->res->forks[philo->fork_index[RIGHT]].value = 1;
			flag = 1;
		}
		pthread_mutex_unlock(&philo->res->forks[philo->fork_index[LEFT]].lock);
		pthread_mutex_unlock(&philo->res->forks[philo->fork_index[RIGHT]].lock);
		if (get_value(&philo->res->end))
			return ;
		if (flag)
			break;
		usleep(500);
	}
	display_message(philo, MSG_TAKE_FORK);
	display_message(philo, MSG_TAKE_FORK);
}

static void	eating(t_philosopher *philo)
{
	pickup(philo);
	set_value(&philo->die_time, get_time() + philo->arg->time_to_die);
	set_value(&philo->eat_count, get_value(&philo->eat_count) + 1);
	display_message(philo, MSG_EATING);
	psleep(philo->res, get_time() + philo->arg->time_to_eat);
	set_value(&philo->res->forks[philo->fork_index[LEFT]], 0);
	set_value(&philo->res->forks[philo->fork_index[RIGHT]], 0);
}

static void	sleeping(t_philosopher *philo)
{
	display_message(philo, MSG_SLEEPING);
	psleep(philo->res, get_time() + philo->arg->time_to_sleep);
}

static void	thinking(t_philosopher *philo)
{
	display_message(philo, MSG_THINKING);
}

void	*philosopher(void *data)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)data;
	if (philo->index % 2)
		psleep(philo->res, get_time() + philo->arg->time_to_eat);
	while (!get_value(&philo->res->end))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
		usleep(500);
	}
	return (0);
}
