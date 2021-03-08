/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:53:23 by ycha              #+#    #+#             */
/*   Updated: 2021/03/03 13:31:35 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parse.h"
#include "ft_string.h"
#include "libft.h"

static int parse_width(char **ptr, va_list *args) {
	int ret;

	if (**ptr == '*')
	{
		(*ptr)++;
		return (va_arg(*args, int));
	}
	ret = 0;
	while ('0' <= **ptr && **ptr <= '9')
	{
		ret *= 10;
		ret += (**ptr - '0');
		(*ptr)++;
	}
	return (ret ? ret : -1);
}

static int parse_precise(char **ptr) {
	int ret;

	if (**ptr != '.')
		return (-1);
	(*ptr)++;
	ret = 0;
	while ('0' <= **ptr && **ptr <= '9')
	{
		ret *= 10;
		ret += (**ptr - '0');
		(*ptr)++;
	}
	return (ret);
}

static int parse_length(char **ptr) {
	int i;
	int len;

	i = -1;
	while (++i < 4) {
		len = (3 - i) / 2 + 1;
		if (ft_strncmp(*ptr, g_parse_length[i], len) == 0) {
			(*ptr) += len;
			return (i);
		}
	}
	return (-1);
}

static char parse_with_string(char **ptr, char *str) {
	char *ret;

	if (ret = ft_strchr(str, **ptr))
		(*ptr)++;
	return (ret ? ret - str : -1);
}

void parse_type(t_parse *tk, char *str) {
	char *ret;

	while (!(ret = ft_strchr(str, **tk->end)))
		(*tk->end)++;
	tk->type = ret - str;
}

void parse_flag(t_parse *tk, char *str) {
	char *ret;

	tk->flag = 0;

}

int parse(t_parse *tk) {
	parse_type(tk, "%cspdiuxX");
	if (**tk->end)
		return (0);
	parse_flag(tk, "-0");
	parse_width(tk);
	parse_precise(tk);
	return(1);
}

