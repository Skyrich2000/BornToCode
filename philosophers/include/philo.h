/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:31:46 by ycha              #+#    #+#             */
/*   Updated: 2021/08/14 05:56:57 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define OK				1
# define ERROR			0
# define TRUE			1
# define FALSE			0

# define LEFT			0
# define RIGHT			1

# define MSG_TAKE_FORK	0
# define MSG_EATING		1
# define MSG_SLEEPING	2
# define MSG_THINKING	3
# define MSG_DEAD		4
# define MSG_ENOUGH		5

typedef struct s_arg
{
	int	number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
}	t_arg;

typedef struct s_data
{
	int				value;
	pthread_mutex_t	lock;
}	t_data;

typedef struct s_resource
{
	int				start;
	t_data			*forks;
	t_data			end;
	pthread_mutex_t	message_lock;
}	t_resource;

typedef struct s_philosopher
{
	int				index;
	int				fork_index[2];
	t_data			eat_count;
	t_data			die_time;
	t_resource		*res;
	t_arg			*arg;

	pthread_t		thread;
}	t_philosopher;

typedef struct s_monitor
{
	t_philosopher	*philos;
	t_resource		*res;
	t_arg			*arg;

	pthread_t		thread;
}	t_monitor;

int		input(int ac, char **av, t_arg *arg);

void	init_data(t_data *data);
void	set_value(t_data *data, int value);
int		get_value(t_data *data);
void	delete_data(t_data *data);

int		get_time(void);
void	psleep(t_resource *res, int end_time);
void	display_message(t_philosopher *philo, int type);

void	init_simulation(t_arg *arg, \
						t_resource *res, \
						t_philosopher **philos, \
						t_monitor *moni);
void	start_simulation(t_arg *arg, t_philosopher *philos, t_monitor *moni);
void	end_simulation(t_arg *arg, \
						t_resource *res, \
						t_philosopher *philos, \
						t_monitor *moni);

void	*philosopher(void *data);
void	*monitor(void *data);

#endif
