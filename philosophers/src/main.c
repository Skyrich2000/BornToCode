/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 03:32:43 by ycha              #+#    #+#             */
/*   Updated: 2021/08/14 05:57:15 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg			arg;
	t_resource		res;
	t_philosopher	*philos;

	if (input(ac, av, &arg))
	{
		init_simulation(&arg, &res, &philos);
		start_simulation(&arg, philos);
		end_simulation(&arg, &res, philos);
	}
	else
		printf("Error\n");
	return (0);
}
