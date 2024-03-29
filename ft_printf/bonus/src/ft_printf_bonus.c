/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:19:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 20:21:23 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int		ft_vprintf(char *str, va_list ap)
{
	int		printed;
	t_flag	flag;

	printed = 0;
	ft_bzero(&flag, sizeof(t_flag));
	while (*str)
	{
		if (*str == '%' && parse(&flag, &str, ap))
			printed += print_arg(&flag, get_arg(&flag, ap, printed));
		else
			printed += write(1, str++, 1);
	}
	return (printed);
}

int		ft_printf(const char *format, ...)
{
	int		printed;
	va_list	ap;

	va_start(ap, format);
	printed = ft_vprintf((char *)format, ap);
	va_end(ap);
	return (printed);
}
