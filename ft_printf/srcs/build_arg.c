/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:25:25 by ycha              #+#    #+#             */
/*   Updated: 2021/03/08 13:07:46 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include "ft_string.h"

#define ZERO 2
#define LEFT 1
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define LEN(str) ((int)ft_strlen(str) + (flag->type == 4) * 2)

int make(t_flag *flag, int zero_padding, char *str) {
	int len;
	int margin;

	len = LEN(str) + MAX(zero_padding, 0);
	margin = MAX(flag->width - len, 0);
	while(!(flag->flag & LEFT) && margin --> 0)
		ft_putchar_fd(' ', 1);
	if (flag->type == 4)
		ft_putstr_fd("0x", 1);
	while(zero_padding --> 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while (margin --> 0)
		ft_putchar_fd(' ', 1);
	free(str);
	return (margin + len);
}

int print_char(t_flag *flag, void *input) {
	int space;
	int zero;
	char str[2];

	str[0] = *(char *)input;
	str[1] = 0;
	return (make(flag, 0, ft_strdup(str)));
}

int print_string(t_flag *flag, void *input) {
	char *str;

	if (*(char **)input == 0)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(*(char **)input);
	return (make(flag, 0, str));
}

int print_p(t_flag *flag, void *input) {
	char *str;

	str = ft_strdup("pointer");
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int print_number(t_flag *flag, void *input) {
	int zero;
	char *str;
	char *tmp;

	zero = 0;
	if (flag->type == 5 || flag->type == 6)
		str = ft_itoa_base(*(long long int *)input, "0123456789");
	else if (flag->type == 7)
		str = ft_itoa_base_unsigned(*(unsigned long long int *)input, "0123456789");
	else if (flag->type == 4 || flag->type == 8)
		str = ft_itoa_base_unsigned(*(unsigned long long int *)input, "0123456789abcdef");
	else if (flag->type == 9)
		str = ft_itoa_base_unsigned(*(unsigned long long int *)input, "0123456789ABCDEF");
	else
		str = 0;
	if (flag->precision != -1)
		zero = MAX(flag->precision - LEN(str), 0);
	else if (flag->flag & ZERO && !(flag->flag & LEFT))
		zero = flag->width - LEN(str);
	return (make(flag, zero, str));
}

int print_u(t_flag *flag, void *input) {
	char *str;

	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int print_x(t_flag *flag, void *input) {
	char *str;

	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int print_X(t_flag *flag, void *input) {
	char *str;

	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
