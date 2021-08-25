/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:09 by ycha              #+#    #+#             */
/*   Updated: 2021/08/14 05:57:31 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*get_message(int type)
{
	if (type == MSG_TAKE_FORK)
		return ("has taken a fork\n");
	else if (type == MSG_EATING)
		return ("is eating\n");
	else if (type == MSG_SLEEPING)
		return ("is sleeping\n");
	else if (type == MSG_THINKING)
		return ("is thinking\n");
	return ("dead\n");
}

void	display_message(t_philosopher *philo, int type)
{
	pthread_mutex_lock(&philo->res->message_lock);
	if (!get_value(&philo->res->end))
	{
		if (type == MSG_ENOUGH)
			printf("%d All philosophers ate it all.\n", \
										(get_time() - philo->res->start) / 1000);
		else
			printf("%d %d %s", (get_time() - philo->res->start) / 1000, \
										philo->index + 1, get_message(type));
	}
	pthread_mutex_unlock(&philo->res->message_lock);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 * 1000 + time.tv_usec);
}

void	psleep(t_resource *res, int end_time)
{
	while (get_time() < end_time)
	{
		usleep(1000);
	}
}
