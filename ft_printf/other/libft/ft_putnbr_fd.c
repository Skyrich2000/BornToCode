/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 18:01:11 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/28 15:55:45 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_div(int input, int fd)
{
	char ch;

	if (input == 0)
		return ;
	ft_div(input / 10, fd);
	ch = '0' + input % 10;
	write(fd, &ch, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	char ch;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_div(-(n / 10), fd);
		ch = '0' - n % 10;
		write(fd, &ch, 1);
	}
	else
	{
		ft_div(n / 10, fd);
		ch = '0' + n % 10;
		write(fd, &ch, 1);
	}
}
