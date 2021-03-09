/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:09 by ycha              #+#    #+#             */
/*   Updated: 2021/03/09 13:08:04 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"

# define MAX(a,b) (((a)>(b))?(a):(b))
# define MIN(a,b) (((a)<(b))?(a):(b))

# define LEFT 1
# define ZERO 2

# define PERCENT 1
# define CHAR 2
# define STRING 4
# define POINTER 8
# define DIGIT 48
# define UDIGIT 64
# define HEXA 128
# define CHEXA 256

typedef struct s_flag {
	int flag;
	int width;
	int only_dot;
	int precision;
	int type;
} t_flag;

typedef struct s_box {
	int zero;
	int len;
	int minus;
	char base[20];
	void *arg;
} t_box;

int ft_printf(const char *format, ...);
void print_flag(t_flag *tk);

int parse(t_flag *tk, char **str, va_list ap);
void get_arg(t_flag *flag, void *arg, va_list ap);

int print_arg(t_flag *flag, void *input);
int get_number_len(unsigned long long int n, int len);
int put_all(t_flag *flag, t_box *box);

#endif
