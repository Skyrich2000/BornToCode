/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:53:23 by ycha              #+#    #+#             */
/*   Updated: 2021/03/20 10:57:55 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_number(char **str, va_list ap)
{
	int	ret;

	ret = 0;
	if (**str == '*')
	{
		(*str)++;
		return (va_arg(ap, int));
	}
	while ('0' <= **str && **str <= '9')
		ret = ret * 10 + *((*str)++) - '0';
	return (ret);
}

static int	parse_char(char **str, char *charset, int repeat)
{
	int		ret;
	char	*ptr;

	ret = 0;
	while (**str && (ptr = ft_strchr(charset, **str)))
	{
		ret |= 1 << (ptr - charset);
		(*str)++;
		if (!repeat)
			break ;
	}
	return (ret);
}

int			parse(t_flag *flag, char **str, va_list ap)
{
	char	*ptr;

	ptr = ++(*str);
	flag->flag = parse_char(&ptr, "-0+ #", 1);
	if ((flag->width = parse_number(&ptr, ap)) < 0)
	{
		flag->width *= -1;
		flag->flag |= LEFT;
	}
	flag->precision = -1;
	if (parse_char(&ptr, ".", 1))
		if ((flag->precision = parse_number(&ptr, ap)) < 0)
			flag->precision = -1;
	if ((flag->length = parse_char(&ptr, "h", 0)))
		flag->length += parse_char(&ptr, "h", 0);
	if ((flag->type = parse_char(&ptr, "%cspdiuxXn", 0)))
		*str = ptr;
	return (flag->type);
}
