/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:59:46 by ycha              #+#    #+#             */
/*   Updated: 2021/08/14 05:57:26 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philosopher(
	t_arg *arg,
	t_resource *res,
	t_philosopher *philo,
	int index
) {
	philo->index = index;
	philo->fork_index[LEFT] = index;
	philo->fork_index[RIGHT] = (index + 1) % arg->number;
	init_data(&philo->eat_count);
	init_data(&philo->die_time);
	set_value(&philo->die_time, res->start + arg->time_to_die);
	philo->res = res;
	philo->arg = arg;
}

void	init_simulation(t_arg *arg, t_resource *res, t_philosopher **philos)
{
	int	i;

	res->forks = (t_data *)malloc(sizeof(t_data) * arg->number);
	*philos = (t_philosopher *)malloc(sizeof(t_philosopher) * arg->number);
	if (!res->forks || !*philos)
		exit(12);
	res->start = get_time();
	init_data(&res->end);
	if (pthread_mutex_init(&res->message_lock, 0) < 0)
		exit(1);
	i = -1;
	while (++i < arg->number)
	{
		init_data(&res->forks[i]);
		init_philosopher(arg, res, &(*philos)[i], i);
	}
}

void	start_simulation(t_arg *arg, t_philosopher *philos)
{
	int	i;

	i = -1;
	while (++i < arg->number)
	{
		if (pthread_create(&philos[i].thread, NULL, \
										philosopher, (void *)(&philos[i])) != 0)
			exit(1);
	}
	pthread_detach(philos[0].thread);
}

void	end_simulation(t_arg *arg, t_resource *res, t_philosopher *philos)
{
	int	i;

	monitoring(arg, philos, &res->end);
	pthread_mutex_destroy(&res->message_lock);
	i = 0;
	while (++i < arg->number)
		pthread_join(philos[i].thread, 0);
	i = -1;
	while (++i < arg->number)
	{
		delete_data(&res->forks[i]);
		delete_data(&philos[i].eat_count);
		delete_data(&philos[i].die_time);
	}
	delete_data(&res->end);
	free(res->forks);
	free(philos);
}
