/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxing_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:25 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 20:20:31 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	boxing_char(t_flag *f, t_box *b)
{
	b->value_len = 1;
	if (f->type & PERCENT)
		b->value = '%';
	if (f->flag & ZERO && !(f->flag & LEFT))
		b->zero = f->width - b->value_len;
}

static void	boxing_string(t_flag *f, t_box *b)
{
	b->value_len = 6;
	if (b->value)
		b->value_len = ft_strlen((char *)b->value);
	if (f->precision != -1 && f->precision < b->value_len)
		b->value_len = f->precision;
	if (f->flag & ZERO && !(f->flag & LEFT))
		b->zero = f->width - b->value_len;
}

static void	boxing_hexa(t_flag *f, t_box *b)
{
	char	*base;

	if (f->type & POINTER || f->flag & HASH)
		b->prefix = 'x' - 32 * ((f->type & CHEXA) > 0);
	base = "0123456789abcdef";
	if (f->type & CHEXA)
		base = "0123456789ABCDEF";
	ft_memcpy(b->base, base, (b->base_len = 16));
	b->value_len = ft_get_number_len((t_ull)b->value, 16);
	if (b->value == 0 && !(f->type & POINTER))
		b->prefix = 0;
	if (f->precision == 0 && b->value == 0)
		b->value_len = 0;
	if (f->precision != -1)
		b->zero = f->precision - b->value_len;
	else if (f->flag & ZERO && !(f->flag & LEFT))
		b->zero = f->width - b->value_len - (b->sign > 0) - (b->prefix > 0) * 2;
}

static void	boxing_number(t_flag *f, t_box *b)
{
	if ((f->flag & SPACE))
		b->sign = ' ';
	if ((f->flag & PLUS))
		b->sign = '+';
	if (b->value < 0)
	{
		b->sign = '-';
		b->value = -b->value;
	}
	ft_memcpy(b->base, "0123456789", (b->base_len = 10));
	b->value_len = ft_get_number_len((t_ull)b->value, 10);
	if (f->precision == 0 && b->value == 0)
		b->value_len = 0;
	if (f->precision != -1)
		b->zero = f->precision - b->value_len;
	else if (f->flag & ZERO && !(f->flag & LEFT))
		b->zero = f->width - b->value_len - (b->sign > 0) - (b->prefix > 0) * 2;
}

int			print_arg(t_flag *flag, t_8byte arg)
{
	int		len;
	t_box	b;

	ft_bzero(&b, sizeof(t_box));
	b.value = arg;
	if (flag->type & NUMBER)
		return (0);
	else if (flag->type & (PERCENT | CHAR))
		boxing_char(flag, &b);
	else if (flag->type & STRING)
		boxing_string(flag, &b);
	else if (flag->type & (DIGIT | UDIGIT))
		boxing_number(flag, &b);
	else if (flag->type & (HEXA | CHEXA | POINTER))
		boxing_hexa(flag, &b);
	len = b.value_len + ft_max(b.zero, 0) + (b.sign > 0) + (b.prefix > 0) * 2;
	b.margin = ft_max(flag->width - len, 0);
	put_all(flag, &b);
	return (b.margin + len);
}
