/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 03:32:43 by ycha              #+#    #+#             */
/*   Updated: 2021/08/13 09:40:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_arg			arg;
	t_resource		res;
	t_monitor		moni;
	t_philosopher	*philos;

	if (input(ac, av, &arg))
	{
		init_simulation(&arg, &res, &philos, &moni);
		start_simulation(&arg, philos, &moni);
		end_simulation(&arg, &res, philos, &moni);
	}
	else
		printf("ERROR\n");
	return (0);
}

