/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:25 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 19:48:11 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	boxing_char(t_flag *flag, t_box *box)
{
	box->value_len = 1;
	if (flag->type & PERCENT)
		box->value = '%';
	if (flag->flag & ZERO && !(flag->flag & LEFT))
		box->zero = flag->width - box->value_len;
}

static void	boxing_string(t_flag *flag, t_box *box)
{
	box->value_len = 6;
	if (box->value)
		box->value_len = ft_strlen((char *)box->value);
	if (flag->precision != -1 && flag->precision < box->value_len)
		box->value_len = flag->precision;
	if (flag->flag & ZERO && !(flag->flag & LEFT))
		box->zero = flag->width - box->value_len;
}

static void	boxing_hexa(t_flag *flag, t_box *box)
{
	char	*base;

	if (flag->type & POINTER || flag->flag & HASH)
		box->prefix = 'x' - 32 * ((flag->type & CHEXA) > 0);
	base = "0123456789abcdef";
	if (flag->type & CHEXA)
		base = "0123456789ABCDEF";
	ft_memcpy(box->base, base, (box->base_len = 16));
	box->value_len = ft_get_number_len((t_ull)box->value, 16);
	if (box->value == 0 && !(flag->type & POINTER))
		box->prefix = 0;
	if (flag->precision == 0 && box->value == 0)
		box->value_len = 0;
	if (flag->precision != -1)
		box->zero = flag->precision - box->value_len;
	else if (flag->flag & ZERO && !(flag->flag & LEFT))
		b->zero = f->width - b->value_len - (b->sign > 0) - (b->prefix > 0) * 2;
}

static void	boxing_number(t_flag *flag, t_box *box)
{
	if ((flag->flag & SPACE))
		box->sign = ' ';
	if ((flag->flag & PLUS))
		box->sign = '+';
	if (box->value < 0)
	{
		box->sign = '-';
		box->value = -box->value;
	}
	ft_memcpy(box->base, "0123456789", (box->base_len = 10));
	box->value_len = ft_get_number_len((t_ull)box->value, 10);
	if (flag->precision == 0 && box->value == 0)
		box->value_len = 0;
	if (flag->precision != -1)
		box->zero = flag->precision - box->value_len;
	else if (flag->flag & ZERO && !(flag->flag & LEFT))
		box->zero = flag->width - box->value_len - (box->sign > 0) - (box->prefix > 0) * 2;
}

int			print_arg(t_flag *flag, t_8byte arg)
{
	int		len;
	t_box	box;

	ft_bzero(&box, sizeof(t_box));
	box.value = arg;
	if (flag->type & NUMBER)
		return (0);
	else if (flag->type & (PERCENT | CHAR))
		boxing_char(flag, &box);
	else if (flag->type & STRING)
		boxing_string(flag, &box);
	else if (flag->type & (DIGIT | UDIGIT))
		boxing_number(flag, &box);
	else if (flag->type & (HEXA | CHEXA | POINTER))
		boxing_hexa(flag, &box);
	len = box.value_len + ft_max(box.zero, 0) + (box.sign > 0) + (box.prefix > 0) * 2;
	box.margin = ft_max(flag->width - len, 0);
	put_all(flag, &box);
	return (box.margin + len);
}
