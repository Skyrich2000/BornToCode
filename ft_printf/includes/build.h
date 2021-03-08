/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:49:09 by ycha              #+#    #+#             */
/*   Updated: 2021/03/08 12:00:45 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUILD_TYPE_H
# define FT_BUILD_TYPE_H
# include "parse.h"
# include <stdarg.h>

void *(*get_arg[10])(int, va_list);
int (*print_arg[10])(t_flag *, void *);

void *get_int(int length, va_list ap);
void *get_unsigned_int(int length, va_list ap);
void *get_pointer(int length, va_list ap);

int print_char(t_flag *flag, void *input);
int print_string(t_flag *flag, void *input);
int print_number(t_flag *flag, void *input);


#endif
