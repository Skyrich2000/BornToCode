/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 14:59:46 by ycha              #+#    #+#             */
/*   Updated: 2021/07/31 14:59:47 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "unistd.h"

void ft_bzero(void *s, size_t n);

#define OK		1
#define ERROR	0

#define S_EAT	0;
#define S_SLEEP	1;
#define S_THINK	2;

typedef int t_fork;

typedef struct s_arg
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
}	t_arg;

pthread_mutex_t	g_mutex_lock;
t_arg			g_arg;

int input(int ac, char **av)
{
	(void)ac;
	(void)av;
	g_arg.number_of_philosophers = 5;
	g_arg.time_to_die = 60;
	g_arg.time_to_eat = 60;
	g_arg.time_to_sleep = 60;
	g_arg.number_of_times_each_philosopher_must_eat = 60;
	return (OK);
}

void *philosopher(void *data)
{
	int		number;
	int		state;
	int		eat_time;
	int		die_time;
	t_fork	forks[2];

	number = ((int *)data)[0];
	forks[0] = ((int *)data)[1];
	forks[1] = ((int *)data)[2];
	die_time = g_arg.time_to_die;
	printf("hi %d %d %d\n", number, forks[0], forks[1]);
	while (die_time)
	{
		pthread_mutex_lock(&g_mutex_lock);

		if (state == S_)

		pthread_mutex_unlock(&g_mutex_lock);
		usleep(100);
		die_time--;
	}
	return (0);
}

int init_simulate(t_fork **forks, pthread_t **threads)
{
	*forks = (t_fork *)malloc(sizeof(t_fork) * g_arg.number_of_philosophers);
	*threads = (pthread_t *)malloc(sizeof(pthread_t) * g_arg.number_of_philosophers);
	ft_bzero(*forks, sizeof(t_fork) * g_arg.number_of_philosophers);
	ft_bzero(*threads, sizeof(pthread_t) * g_arg.number_of_philosophers);
	(*forks)[g_arg.number_of_philosophers] = (*forks)[0];
	return (OK);
}

int start_simulate(t_fork *forks, pthread_t *threads)
{
	int	i;

	i = 0;
	pthread_mutex_init(&g_mutex_lock, NULL);
	pthread_create(&threads[0], NULL, philosopher, (void *)(int [3]){0, forks[g_arg.number_of_philosophers], forks[0]});
	while (++i < g_arg.number_of_philosophers)
	{
		pthread_create(&threads[i], NULL, philosopher, (void *)(int [3]){i, forks[i], forks[i + 1]});
		usleep(1000);
	}
	return (OK);
}

int end_simulate(t_fork *forks, pthread_t *threads)
{
	int i;

	i = -1;
	while (++i < g_arg.number_of_philosophers)
		pthread_join(threads[i], 0);
	pthread_mutex_destroy(&g_mutex_lock);
	free(forks);
	return (OK);
}

int	main(int ac, char **av)
{
	t_fork		*forks;
	pthread_t	*threads;

	if (input(ac, av))
	{
		init_simulate(&forks, &threads);
		start_simulate(forks, threads);
		end_simulate(forks, threads);
	}
	else
		printf("ERROR\n");
	return (0);
}
