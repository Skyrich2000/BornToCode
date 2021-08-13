/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 03:34:27 by ycha              #+#    #+#             */
/*   Updated: 2021/08/13 17:31:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int input(int ac, char **av, t_arg *arg)
{
	(void)ac;
	(void)av;
	arg->number = 4;
	arg->time_to_die = 410;
	arg->time_to_eat = 200;
	arg->time_to_sleep = 200;
	arg->must_eat_count = -1;
	return (OK);
}
