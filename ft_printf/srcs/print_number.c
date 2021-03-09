/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:50:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/09 13:36:08 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_number_len(unsigned long long int n, int len)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= len;
		++i;
	}
	return (i);
}

void put_number(unsigned long long int n, char *base, int len)
{
	if (n > (unsigned int)len - 1)
		put_number(n / len, base, len);
	ft_putchar_fd(base[n % len], 1);
}

void put_string(void *arg, int len)
{
	if (*(char **)arg == 0)
		write(1, "(null)", len);
	else
		write(1, *(char **)arg, len);
}

int put_all(t_flag *flag, t_box *box)
{
	int len;
	int margin;

	len = box->len + MAX(box->zero, 0) + box->minus;
	margin = MAX(flag->width - len, 0);
	while(!(flag->flag & LEFT) && margin --> 0)
		ft_putchar_fd(' ', 1);
	if (flag->type & POINTER)
		write(1, "0x", 2);
	if (box->minus)
		write(1, "-", 1);
	while(box->zero --> 0)
		ft_putchar_fd('0', 1);
	if (flag->type & (STRING | CHAR))
		put_string(box->arg, box->len);
	else if (box->len)
		put_number(*(unsigned long long int *)(box->arg), box->base, ft_strlen(box->base));
	while (margin --> 0)
		ft_putchar_fd(' ', 1);
	return (MAX(flag->width - len, 0) + len);
}
