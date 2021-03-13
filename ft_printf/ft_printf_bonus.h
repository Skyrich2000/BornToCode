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

typedef long long t_8byte;
typedef long long t_ll;
typedef unsigned long long t_ull;

typedef struct s_flag {
	int flag;
	int width;
	int precision;
	int length;
	int type;
} t_flag;

typedef struct s_box {
	int minus;
	int is_pointer;
	int zero;
	int len;
	int margin;
	char base[20]; //char *base;
	int base_len;
	t_8byte arg;
} t_box;

int ft_printf(const char *format, ...);

int parse(t_flag *tk, char **str, va_list ap);
int print_arg(t_flag *flag, t_8byte input);
void put_all(t_flag *flag, t_box *box);

#endif