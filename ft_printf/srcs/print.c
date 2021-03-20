/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:50:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 19:34:58 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_char_n(char chr, int n)
{
	while (n-- > 0)
		write(1, &chr, 1);
}

static void	put_string(char *str, int len)
{
	if (str == 0)
		write(1, "(null)", len);
	else
		write(1, str, len);
}

static void	put_number(t_ull n, char *base, int len)
{
	if (n > (unsigned int)len - 1)
		put_number(n / len, base, len);
	write(1, &(base[n % len]), 1);
}

void		put_all(t_flag *flag, t_box *box)
{
	put_char_n(' ', !(flag->flag & LEFT) * box->margin);
	put_char_n(box->sign, box->sign > 0);
	put_char_n('0', box->prefix > 0);
	put_char_n(box->prefix, box->prefix > 0);
	put_char_n('0', box->zero);
	if (flag->type & (PERCENT | CHAR))
		put_char_n((char)box->value, 1);
	else if (flag->type & STRING)
		put_string((char *)box->value, box->value_len);
	else if (box->value_len)
		put_number((t_ull)box->value, box->base, box->base_len);
	put_char_n(' ', (flag->flag & LEFT) * box->margin);
}
