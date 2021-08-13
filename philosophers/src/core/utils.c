/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:09 by ycha              #+#    #+#             */
/*   Updated: 2021/08/13 01:36:26 by ycha             ###   ########.fr       */
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

int		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	psleep(t_resource *res, int end_time)
{
	while (get_time() < end_time)
	{
		if (get_value(&res->end))
			return ;
		usleep(10);
	}
}

void	display_message(t_philosopher *philo, int type)
{
	pthread_mutex_lock(&philo->res->message_lock);
	if (!get_value(&philo->res->end))
	{
		if (type == MSG_ENOUGH)
			printf("%dms All philosophers ate it all.\n", get_time() - philo->res->start);
		else
			printf("%dms %d %s", get_time() - philo->res->start, philo->index + 1, get_message(type));
	}
	pthread_mutex_unlock(&philo->res->message_lock);
}
