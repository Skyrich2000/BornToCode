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

int	is_num(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (ERROR);
		str++;
	}
	return (OK);
}

int	ft_atoi(char *str, int *data)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	if (!is_num(str))
		return (ERROR);
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	result *= sign;
	*data = result;
	return (OK);
}

int	input(int ac, char **av, t_arg *arg)
{
	if (ac < 5 || ac > 6)
		return (ERROR);
	arg->must_eat_count = -1;
	if (!ft_atoi(av[1], &arg->number) || \
		!ft_atoi(av[2], &arg->time_to_die) || \
		!ft_atoi(av[3], &arg->time_to_eat) || \
		!ft_atoi(av[4], &arg->time_to_sleep) || \
		(ac == 6 && (!ft_atoi(av[5], &arg->must_eat_count))))
		return (ERROR);
	return (OK);
}
