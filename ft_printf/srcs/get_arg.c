/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:31:32 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 10:57:50 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void		handle_number(t_flag *flag, va_list ap, int printed)
{
	t_8byte	value;

	value = (t_8byte)va_arg(ap, void *);
	if (flag->length == 0)
		*(int *)value = printed;
	else if (flag->length == 1)
		*(short int *)value = printed;
	else
		*(signed char *)value = printed;
}

t_8byte			get_arg(t_flag *flag, va_list ap, int printed)
{
	if (flag->type & PERCENT)
		return (0);
	else if (flag->type & (STRING | POINTER))
		return ((t_8byte)va_arg(ap, void *));
	else if (flag->type & (CHAR | DIGIT))
		return (get_int(flag->length, ap));
	else if (flag->type & (UDIGIT | HEXA | CHEXA))
		return (get_unsigned_int(flag->length, ap));
	else if (flag->type & NUMBER)
		handle_number(flag, ap, printed);
	return (0);
}
