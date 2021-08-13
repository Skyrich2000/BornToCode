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

int	is_end(t_philosopher *philo)
{
	if (get_value(&philo->res->dead) == 1)
		return (TRUE);
	if (philo->die_time < get_time())
	{
		set_value(&philo->res->dead, 1);
		display_message(philo, MSG_DEAD);
		return (TRUE);
	}
	if (get_value(&philo->res->eat_count) == 0)
		return (TURE);
	return (FALSE);
}

void	*moniter(void *data)
{
	t_moniter	*self;

	self = (t_moniter)data;
	while (is_end())
		usleep(10);

	return (0);
}

int	thinking(t_philosopher *philo)
{
	display_message(philo, MSG_THINKING);
	while (1)
	{
		if (get_value(&philo->res->forks[philo->fork_index[LEFT]]) == 0 && \
			get_value(&philo->res->forks[philo->fork_index[RIGHT]]) == 0)
			return (OK);
	}
	return (OK);
}

int	eating(t_philosopher *philo)
{
	int eat_end_time;
	int	eat_count;

	display_message(philo, MSG_EATING);
	set_value(&philo->res->forks[philo->fork_index[LEFT]], 1);
	display_message(philo, MSG_TAKE_FORK);
	set_value(&philo->res->forks[philo->fork_index[RIGHT]], 1);
	display_message(philo, MSG_TAKE_FORK);
	eat_count = get_value(&philo->res->eat_count);
	if (eat_count != -1)
		set_value(&philo->res->eat_count, eat_count + 1);
	eat_end_time = get_time() + philo->arg->time_to_sleep;
	while (get_time() < eat_end_time)
		usleep(10);
	set_value(&philo->res->forks[philo->fork_index[LEFT]], 0);
	set_value(&philo->res->forks[philo->fork_index[RIGHT]], 0);
	philo->die_time += philo->arg->time_to_die;
	return (OK);
}

int	sleeping(t_philosopher *philo)
{
	int sleep_end_time;

	display_message(philo, MSG_SLEEPING);
	sleep_end_time = get_time() + philo->arg->time_to_sleep;
	while (get_time() < sleep_end_time)
	{
		if (is_end(philo))
			return (ERROR);
		usleep(10);
	}
	return (OK);
}

void	*philosopher(void *data)
{
	t_philosopher *philo;

	philo = (t_philosopher *)data;
	while (1)
	{
		if (is_end(philo) || !thinking(phiolo))
			break;
		if (is_end(philo) || !eating(philo))
			break;
		if (is_end(philo) || !sleeping(philo))
			break;
	}
	return (0);
}

int init_simulation(t_arg *arg, t_resource *res, t_philosopher **philos, t_moniter	*moni)
{
	int i;

	res->forks = (t_data *)malloc(sizeof(t_data) * arg->number);
	*philos = (t_philosopher *)malloc(sizeof(t_philosopher) * arg->number);
	if (!res->forks || !*philos)
		exit(12);
	i = -1;
	res->start = get_time();
	init_data(&res->eat_count);
	pthread_mutex_init(&res->message_lock, 0);
	while (++i < arg->number)
	{
		init_data(&res->forks[i]);
		(*philos)[i].index = i;
		(*philos)[i].die_time = res->start + arg->time_to_die;
		(*philos)[i].fork_index[LEFT] = i;
		(*philos)[i].fork_index[RIGHT] = (i + 1) % arg->number;
		(*philos)[i].res = res;
		(*philos)[i].arg = arg;
	}
	moni->philos = *philos;
	moni->res = *res;
	return (OK);
}

int start_simulation(t_arg *arg, t_philosopher *philos, pthread_t *threads)
{
	int	i;

	i = -1;
	while (++i < arg->number)
		pthread_create(&philos[i].thread, NULL, philosopher, (void *)(&philos[i]));
	return (OK);
}

int end_simulation(t_arg *arg, t_resource *res, t_philosopher *philos, pthread_t *threads)
{
	int i;

	i = -1;
	while (++i < arg->number)
		pthread_join(threads[i], 0);
	while (++i < arg->number)
		delete_data(&res->forks[i]);
	delete_data(&res->eat_count);
	pthread_mutex_destroy(&res->message_lock);
	free(res->forks);
	free(philos);
	return (OK);
}

