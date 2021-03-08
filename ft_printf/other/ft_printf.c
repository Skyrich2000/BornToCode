/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:15:50 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/09 13:31:06 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_flag *t)
{
	t->left = 0;
	t->zero = 0;
	t->width = 0;
	t->dot = 0;
	t->precision = 0;
	t->padding = ' ';
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		flag;
	int			cnt;

	va_start(ap, fmt);
	ft_init(&flag);
	cnt = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt++, 1);
			cnt++;
			continue;
		}
		fmt++;
		cnt += ft_parse(&fmt, &flag, ap);
		fmt++;
		ft_init(&flag);
	}
	return (cnt);
}
