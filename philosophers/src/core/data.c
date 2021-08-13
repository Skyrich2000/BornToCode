/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 04:14:10 by ycha              #+#    #+#             */
/*   Updated: 2021/08/13 08:22:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_data(t_data *data)
{
	data->value = 0;
	pthread_mutex_init(&data->lock, 0);
}

void	set_value(t_data *data, int value)
{
	pthread_mutex_lock(&data->lock);
	data->value = value;
	pthread_mutex_unlock(&data->lock);
}

int	get_value(t_data *data)
{
	int value;

	pthread_mutex_lock(&data->lock);
	value = data->value;
	pthread_mutex_unlock(&data->lock);
	return (value);
}

void	delete_data(t_data *data)
{
	pthread_mutex_destroy(&data->lock);
}
