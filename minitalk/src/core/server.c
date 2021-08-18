/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 02:14:04 by ycha              #+#    #+#             */
/*   Updated: 2021/07/05 16:12:58 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define BUFFER_SIZE 8

static void	sig_handler(int signo)
{
	static char	buf = 0;
	static int	size = 0;

	buf |= (signo == SIGUSR1) << size;
	size++;
	if (size >= BUFFER_SIZE)
	{
		ft_putchar_fd(buf, 1);
		buf = 0;
		size = 0;
	}
}

int			main(void)
{
	if (signal(SIGUSR1, sig_handler) == SIG_ERR ||
		signal(SIGUSR2, sig_handler) == SIG_ERR)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_putstr_fd("server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
