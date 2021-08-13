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

int	is_dead(t_monitor *self)
{
	int i;

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

int	is_all_ate(t_monitor *self)
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

void	thinking(t_philosopher *philo)
{
	display_message(philo, MSG_THINKING);
	while (1)
	{
		if (get_value(&philo->res->forks[philo->fork_index[LEFT]]) == 0 && \
			get_value(&philo->res->forks[philo->fork_index[RIGHT]]) == 0)
			break;
	}
}

void	eating(t_philosopher *philo)
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

void	sleeping(t_philosopher *philo)
{
	display_message(philo, MSG_SLEEPING);
	psleep(philo->res, get_time() + philo->arg->time_to_sleep);
}

void	*philosopher(void *data)
{
	t_philosopher *philo;

	philo = (t_philosopher *)data;
	while (!get_value(&philo->res->end))
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (0);
}

int init_simulation(t_arg *arg, t_resource *res, t_philosopher **philos, t_monitor *moni)
{
	int i;

	res->forks = (t_data *)malloc(sizeof(t_data) * arg->number);
	*philos = (t_philosopher *)malloc(sizeof(t_philosopher) * arg->number);
	if (!res->forks || !*philos)
		exit(12);
	i = -1;
	res->start = get_time();
	init_data(&res->end);
	pthread_mutex_init(&res->message_lock, 0);
	while (++i < arg->number)
	{
		init_data(&res->forks[i]);
		(*philos)[i].index = i;
		(*philos)[i].fork_index[LEFT] = i;
		(*philos)[i].fork_index[RIGHT] = (i + 1) % arg->number;
		init_data(&(*philos)[i].eat_count);
		init_data(&(*philos)[i].die_time);
		set_value(&(*philos)[i].die_time, res->start + arg->time_to_die);
		(*philos)[i].res = res;
		(*philos)[i].arg = arg;
	}
	moni->philos = *philos;
	moni->res = res;
	moni->arg = arg;
	return (OK);
}

int start_simulation(t_arg *arg, t_philosopher *philos, t_monitor *moni)
{
	int	i;

	i = -1;
	while (++i < arg->number)
		pthread_create(&philos[i].thread, NULL, philosopher, (void *)(&philos[i]));
	pthread_create(&moni->thread, NULL, monitor, (void *)moni);
	return (OK);
}

int end_simulation(t_arg *arg, t_resource *res, t_philosopher *philos, t_monitor *moni)
{
	int i;

	i = -1;
	pthread_join(moni->thread, 0);
	while (++i < arg->number)
		pthread_join(philos[i].thread, 0);

	while (++i < arg->number)
	{
		delete_data(&res->forks[i]);
		delete_data(&philos[i].eat_count);
		delete_data(&philos[i].die_time);
	}
	delete_data(&res->end);
	pthread_mutex_destroy(&res->message_lock);
	free(res->forks);
	free(philos);
	return (OK);
}