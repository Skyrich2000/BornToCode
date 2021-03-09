/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:53:23 by ycha              #+#    #+#             */
/*   Updated: 2021/03/09 13:52:46 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int parse_number(char **str, va_list ap) {
	int ret;

	ret = 0;
	if (**str == '*')
	{
		(*str)++;
		return (va_arg(ap, int));
	}
	while (ft_isdigit(**str))
		ret = ret * 10 + *((*str)++) - '0';
	return (ret);
}

static int parse_char(char **str, char *charset, int repeat) {
	int ret;
	char *ptr;

	ret = 0;
	while (**str && (ptr = ft_strchr(charset, **str)))
	{
		ret |= 1 << (ptr - charset);
		(*str)++;
		if (!repeat)
			break;
	}
	return (ret);
}

int parse(t_flag *flag, char **str, va_list ap) {
	char *ptr;

	ptr = ++(*str);
	flag->flag = parse_char(&ptr, "-0", 1);
	if ((flag->width = parse_number(&ptr, ap)) < 0)
	{
		flag->width *= -1;
		flag->flag |= LEFT;
	}
	flag->precision = -1;
	if ((flag->only_dot = parse_char(&ptr, ".", 1)))
	{
		if (('0' <= *ptr && *ptr <= '9') || *ptr == '*')
			flag->only_dot = 0;
		if ((flag->precision = parse_number(&ptr, ap)) < 0)
			flag->precision = 0;
	}
	if ((flag->type = parse_char(&ptr, "%cspdiuxX", 0)))
		*str = ptr;
	return (flag->type);
}

void print_flag(t_flag *tk) {
	printf("{flag %d, width %d, precision %d, type %d}\n", tk->flag ,tk->width, tk->precision, tk->type);
}

