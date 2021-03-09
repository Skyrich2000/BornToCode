/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:25 by ycha              #+#    #+#             */
/*   Updated: 2021/03/09 13:45:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_arg(t_flag *flag, void *arg)
{
	char tmp[2];
	t_box box;

	box.minus = 0;
	box.zero = 0;
	box.arg = arg;
	if (flag->type & (PERCENT | CHAR))
	{
		box.len = 1;
		tmp[0] = flag->type & PERCENT ? '%' : *(char *)box.arg;
		tmp[1] = 0;
		*(char **)(box.arg) = tmp;
	}
	else if (flag->type & STRING)
	{
		box.len = ft_strlen(*(char **)arg);
		if (flag->precision != -1)
			box.len = MIN(flag->precision, box.len);
	}
	else
	{
		if (flag->type & DIGIT)
		{
			if (*(long long int *)arg < 0)
			{
				box.minus = 1;
				*(long long int*)(box.arg) = -*(long long int*)arg;
			}
			ft_memcpy(box.base, "0123456789", 11);
			box.len = get_number_len(*(long long int *)(box.arg), 10);
		}
		else if (flag->type & UDIGIT)
		{
			ft_memcpy(box.base, "0123456789", 11);
			box.len = get_number_len(*(unsigned long long int *)(box.arg), 10);
		}
		else if (flag->type & (POINTER | HEXA))
		{
			ft_memcpy(box.base, "0123456789abcdef", 17);
			box.len = get_number_len(*(unsigned long long int *)(box.arg), 16);
			if (flag->type & POINTER)
				box.len += 2;
		}
		else
		{
			ft_memcpy(box.base, "0123456789ABCDEF", 17);
			box.len = get_number_len(*(unsigned long long int *)(box.arg), 16);
		}
		if (flag->precision != -1)
			box.zero = MAX(flag->precision - box.len, 0);
		else if (flag->flag & ZERO && !(flag->flag & LEFT))
			box.zero = flag->width - box.len - box.minus;
		if (flag->precision == 0 && *(unsigned long long int *)arg == 0)
			box.len = 0;
	}
	return (put_all(flag, &box));
}
