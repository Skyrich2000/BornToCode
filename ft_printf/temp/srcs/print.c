/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:50:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/13 16:11:21 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_char(char arg)
{
	write(1, &arg, 1);
}

static void put_string(char *arg, int len)
{
	if (arg == 0)
		write(1, "(null)", len);
	else
		write(1, arg, len);
}

static void put_number(t_ull n, char *base, int len) //max number check
{
	if (n > (unsigned int)len - 1)
		put_number(n / len, base, len);
	ft_putchar_fd(base[n % len], 1);
}

void put_all(t_flag *flag, t_box *box)
{
	while(!(flag->flag & LEFT) && box->margin --> 0)
		ft_putchar_fd(' ', 1);
	if (box->is_pointer)
		write(1, "0x", 2);
	if (box->minus)
		write(1, "-", 1);
	while(box->zero --> 0)
		ft_putchar_fd('0', 1);
	if (flag->type & (PERCENT | CHAR))
		put_char((char)box->arg);
	else if (flag->type & STRING)
		put_string((char *)box->arg, box->len);
	else if (box->len)
		put_number((t_ull)box->arg, box->base, box->base_len);
	while (box->margin --> 0)
		ft_putchar_fd(' ', 1);
}
