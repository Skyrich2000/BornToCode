/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:50:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 10:58:03 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_char_n(int fd, char chr, int n)
{
	while (n-- > 0)
		write(fd, &chr, 1);
}

static void	put_string(int fd, char *str, int len)
{
	if (str == 0)
		write(fd, "(null)", len);
	else
		write(fd, str, len);
}

static void	put_number(int fd, t_ull n, char *base, int len)
{
	if (n > (unsigned int)len - 1)
		put_number(fd, n / len, base, len);
	write(fd, &(base[n % len]), 1);
}

void	put_all(int fd, t_flag *flag, t_box *box)
{
	put_char_n(fd, ' ', !(flag->flag & LEFT) * box->margin);
	put_char_n(fd, box->sign, box->sign > 0);
	put_char_n(fd, '0', box->prefix > 0);
	put_char_n(fd, box->prefix, box->prefix > 0);
	put_char_n(fd, '0', box->zero);
	if (flag->type & (PERCENT | CHAR))
		put_char_n(fd, (char)box->value, 1);
	else if (flag->type & STRING)
		put_string(fd, (char *)box->value, box->value_len);
	else if (box->value_len)
		put_number(fd, (t_ull)box->value, box->base, box->base_len);
	put_char_n(fd, ' ', (flag->flag & LEFT) * box->margin);
}
