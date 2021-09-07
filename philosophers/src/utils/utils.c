/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:25:09 by ycha              #+#    #+#             */
/*   Updated: 2021/09/07 17:20:31 by ycha             ###   ########.fr       */
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
	static int	end = 0;

	pthread_mutex_lock(&philo->res->message_lock);
	if (!end)
	{
		if (type == MSG_ENOUGH)
			printf("%d All philosophers ate it all.\n", \
									get_time() - philo->res->start);
		else
			printf("%d %d %s", get_time() - philo->res->start, \
										philo->index + 1, get_message(type));
		if (type == MSG_DEAD || type == MSG_ENOUGH)
			end = 1;
	}
	pthread_mutex_unlock(&philo->res->message_lock);
}

int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

// TODO: return if ended
void	psleep(int end_time)
{
	while (get_time() < end_time)
		usleep(200);
}
