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

void get_int(int length, long long int *arg, va_list ap) {
	if (length == 0)
		*arg = va_arg(ap, int);
	else if (length == 1)
		*arg = va_arg(ap, long long int);
	else if (length == 2)
		*arg = va_arg(ap, int); // signed char);
	else if (length == 3)
		*arg = va_arg(ap, long int);
	else
		*arg = va_arg(ap, int); //short int);
}

void get_unsigned_int(int length, unsigned long long int *arg, va_list ap) {
	if (length == 0)
		*arg = va_arg(ap, unsigned int);
	else if (length == 1)
		*arg = va_arg(ap, unsigned long long int);
	else if (length == 2)
		*arg = va_arg(ap, int ); //unsigned char);
	else if (length == 3)
		*arg = va_arg(ap, unsigned long int);
	else
		*arg = va_arg(ap, int ); //unsigned short int);
}

void get_pointer(void *arg, va_list ap) {
	*(void **)arg = va_arg(ap, void *);
}

void get_arg(t_flag *flag, void *arg, va_list ap)
{
	if (flag->type & (STRING | POINTER))
		get_pointer(arg, ap);
	else if (flag->type & (CHAR | DIGIT))
		get_int(0, (long long int *)arg, ap);
	else if (flag->type & (UDIGIT | HEXA | CHEXA))
		get_unsigned_int(0, (unsigned long long int *)arg, ap);
}
