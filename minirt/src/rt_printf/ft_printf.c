/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:19:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 10:57:27 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vfprintf(int fd, char *str, va_list *ap)
{
	int		printed;
	t_flag	flag;

	printed = 0;
	ft_bzero(&flag, sizeof(t_flag));
	while (*str)
	{
		if (*str == '%' && parse(&flag, &str, ap))
			printed += print_arg(fd, &flag, get_arg(&flag, ap, printed));
		else
			printed += write(fd, str++, 1);
	}
	return (printed);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	int		printed;
	va_list	ap;

	va_start(ap, format);
	printed = ft_vfprintf(fd, (char *)format, &ap);
	va_end(ap);
	return (printed);
}
