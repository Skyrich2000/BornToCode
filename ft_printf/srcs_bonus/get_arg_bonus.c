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

#include "ft_printf_bonus.h"

static t_8byte	get_int(int length, va_list ap)
{
	if (length == 0)
		return ((t_8byte)va_arg(ap, int));
	else if (length == 1)
		return ((t_8byte)va_arg(ap, int)); //short int));
	else
		return ((t_8byte)va_arg(ap, int)); //signed char));
}

static t_8byte	get_unsigned_int(int length, va_list ap)
{
	if (length == 0)
		return ((t_8byte)va_arg(ap, unsigned int));
	else if (length == 1)
		return ((t_8byte)va_arg(ap, unsigned int)); //short int));
	else
		return ((t_8byte)va_arg(ap, unsigned int)); //char));
}

static t_8byte	get_pointer(va_list ap)
{
	return ((t_8byte)va_arg(ap, void *));
}

t_8byte			get_arg(t_flag *flag, va_list ap)
{
	if (flag->type & (STRING | POINTER))
		return (get_pointer(ap));
	else if (flag->type & (CHAR | DIGIT))
		return (get_int(flag->length, ap));
	return (get_unsigned_int(flag->length, ap));
}
