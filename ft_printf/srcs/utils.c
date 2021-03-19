/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 18:43:19 by ycha              #+#    #+#             */
/*   Updated: 2021/03/09 11:40:24 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

int	get_number_len(t_ull n, int len)
{
	int	i;

	i = 1;
	while ((n /= len) > 0)
		++i;
	return (i);
}

static t_8byte	get_int(int length, va_list ap)
{
	t_8byte value;

	value = va_arg(ap, int);
	if (length == 0)
		return (value);
	else if (length == 1)
		return ((short int)value);
	return ((signed char)value);
}

static t_8byte	get_unsigned_int(int length, va_list ap)
{
	t_8byte value;

	value = va_arg(ap, unsigned int);
	if (length == 0)
		return (value);
	else if (length == 1)
		return ((short unsigned int)value);
	return ((unsigned char)value);
}

t_8byte			get_arg(t_flag *flag, va_list ap)
{
	if (flag->type & PERCENT)
		return (0);
	else if (flag->type & (STRING | POINTER | NUMBER))
		return ((t_8byte)va_arg(ap, void *));
	else if (flag->type & (CHAR | DIGIT))
		return (get_int(flag->length, ap));
	return (get_unsigned_int(flag->length, ap));
}
