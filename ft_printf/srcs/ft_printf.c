/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:19:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/07 13:41:06 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_string.h"
#include "parse.h"
#include "libft.h"
#include "build.h"

void init();

int build(t_flag *flag, va_list ap)
{
	void *arg;
	int ret;

	if (flag->type == 1)
		return (1);
	if (!(arg = get_arg[flag->type](0, ap)))
		return (0);
	ret = print_arg[flag->type](flag, arg);
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
			i += build(&flag, ap);
		else
			write(1, str++, 1) && i++;
	}
	return (i);
}

int ft_printf(const char *format, ...) {
	int printed;
	va_list ap;

	init();
	va_start(ap, format);
	printed = ft_vprintf((char *)format, ap);
	va_end(ap);
	return (printed);
}
