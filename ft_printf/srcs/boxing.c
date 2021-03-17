/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:25 by ycha              #+#    #+#             */
/*   Updated: 2021/03/14 01:32:36 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_number_len(t_ull n, int len)
{
	int	i;

	i = 1;
	while ((n /= len) > 0)
		++i;
	return (i);
}

static void	boxing_char(t_flag *flag, t_box *box)
{
	box->len = 1;
	if (flag->type & PERCENT)
		box->arg = '%';
	if (flag->flag & ZERO && !(flag->flag & LEFT))
		box->zero = flag->width - box->len - box->sign - box->prefix;
}

static void	boxing_string(t_flag *flag, t_box *box)
{
	box->len = box->arg ? ft_strlen((char *)box->arg) : 6;
	if (flag->precision != -1 && flag->precision < box->len)
		box->len = flag->precision;
	if (flag->flag & ZERO && !(flag->flag & LEFT))
		box->zero = flag->width - box->len - box->sign - box->prefix;
}

static void	boxing_number(t_flag *flag, t_box *box)
{
	char	*base;

	if ((flag->type & DIGIT) && box->arg < 0)
	{
		box->sign = 1;
		box->arg = -box->arg;
	}
	box->prefix = (flag->type & POINTER) / POINTER * 2;
	base = "0123456789abcdef";
	if (flag->type & CHEXA)
		base = "0123456789ABCDEF";
	box->base_len = 10;
	if (flag->type & (POINTER | HEXA | CHEXA))
		box->base_len = 16;
	ft_memcpy(box->base, base, box->base_len);
	box->len = get_number_len((t_ull)box->arg, box->base_len);
	if (flag->precision == 0 && box->arg == 0)
		box->len = 0;
	if (flag->precision != -1)
		box->zero = flag->precision - box->len;
	else if (flag->flag & ZERO && !(flag->flag & LEFT))
		box->zero = flag->width - box->len - box->sign - box->prefix;
}

int			print_arg(t_flag *flag, t_8byte arg)
{
	int		content;
	t_box	box;

	ft_bzero(&box, sizeof(t_box));
	box.arg = arg;
	if (flag->type & (PERCENT | CHAR))
		boxing_char(flag, &box);
	else if (flag->type & STRING)
		boxing_string(flag, &box);
	else
		boxing_number(flag, &box);
	content = box.len + ft_max(box.zero, 0) + box.sign + box.prefix;
	box.margin = ft_max(flag->width - content, 0);
	put_all(flag, &box);
	return (ft_max(flag->width - content, 0) + content);
}
