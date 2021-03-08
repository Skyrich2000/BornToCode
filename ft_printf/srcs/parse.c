/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:53:23 by ycha              #+#    #+#             */
/*   Updated: 2021/03/07 13:57:51 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parse.h"
#include "ft_string.h"
#include "libft.h"

#define MAX(a,b) (((a)>(b))?(a):(b))

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

static int parse_char(char **str, char *charset) {
	int ret;
	char *ptr;

	ret = 0;
	while (**str && (ptr = ft_strchr(charset, **str)))
	{
		ret |= 1 << (ptr - charset);
		(*str)++;
	}
	return (ret);
}

static int parse_type(char **str, char *charset) {
	char *ptr;

	if (**str && (ptr = ft_strchr(charset, **str)))
	{
		(*str)++;
		return (ptr - charset + 1);
	}
	return (0);
}

int parse(t_flag *flag, char **str, va_list ap) {
	char *ptr;

	ptr = ++(*str);
	flag->flag = parse_char(&ptr, "-0");
	if ((flag->width = parse_number(&ptr, ap)) < 0)
	{
		flag->width *= -1;
		flag->flag |= 1;
	}
	flag->precision = -1;
	if (parse_char(&ptr, "."))
	{
		flag->precision = parse_number(&ptr, ap);
		flag->precision = MAX(flag->precision, 0);
	}
	if ((flag->type = parse_type(&ptr, "%cspdiuxX")))
		*str = ptr;
	return (flag->type);
}

void print_flag(t_flag *tk) {
	printf("{flag %d, width %d, precision %d, type %d}", tk->flag ,tk->width, tk->precision, tk->type);
}

