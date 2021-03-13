/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:19:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/09 13:30:39 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_8byte get_arg(t_flag *flag, va_list ap)
{
	if (flag->type & PERCENT)
		return (0);
	else if (flag->type & (STRING | POINTER))
		return ((t_8byte)va_arg(ap, void *));
	else if (flag->type & (CHAR | DIGIT))
		return ((t_8byte)va_arg(ap, int));
	return ((t_8byte)va_arg(ap, unsigned int));
}

int ft_vprintf(char *str, va_list ap) {
	int printed;
	t_flag flag;

	printed = 0;
	ft_bzero(&flag, sizeof(t_flag));
	while (*str)
	{
		if (*str == '%' && parse(&flag, &str, ap))
			printed += print_arg(&flag, get_arg(&flag, ap));
		else
		{
			write(1, str++, 1);
			printed++;
		}
	}
	return (printed);
}

int ft_printf(const char *format, ...) {
	int printed;
	va_list ap;

	va_start(ap, format);
	printed = ft_vprintf((char *)format, ap);
	va_end(ap);
	return (printed);
}
