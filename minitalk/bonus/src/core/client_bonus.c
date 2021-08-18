/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 02:14:01 by ycha              #+#    #+#             */
/*   Updated: 2021/07/05 16:06:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

#define PID_MIN 0
#define PID_MAX 99999

static void	send(int pid, char *str)
{
	int i;

	while (*str)
	{
		i = -1;
		while (++i < 8)
		{
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		str++;
	}
}

int			main(int ac, char **av)
{
	int pid;

	if (ac == 3 && is_num(av[1]) && ft_atoi(av[1], &pid) && \
		(PID_MIN < pid && pid < PID_MAX))
		send(pid, av[2]);
	else
		ft_putstr_fd("Error\n", 2);
	return (0);
}
