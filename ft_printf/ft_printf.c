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

int print(t_flag *flag, va_list ap)
{
	void *arg;
	int ret;

//	print_flag(flag);
	if (!(arg = malloc(32)))
		return (0);
	ft_bzero(arg, 32);
	get_arg(flag, arg, ap);
	ret = print_arg(flag, arg);
	free(arg);
	return (ret);
}

int ft_vprintf(char *str, va_list ap) {
	int i;
	t_flag flag;

	i = 0;
	while (*str)
	{
		if (*str == '%' && parse(&flag, &str, ap))
			i += print(&flag, ap);
		else
		{
			write(1, str++, 1);
			i++;
		}
	}
	return (i);
}

int ft_printf(const char *format, ...) {
	int printed;
	va_list ap;

	va_start(ap, format);
	printed = ft_vprintf((char *)format, ap);
	va_end(ap);
	return (printed);
}
