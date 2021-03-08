/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:52:58 by ycha              #+#    #+#             */
/*   Updated: 2021/03/07 13:52:23 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include <stdarg.h>

typedef struct s_flag {
	int flag; //left 1 zero 2 both 3
	int width; //0 or int
	int precision; //0 or int
	int type; //0010000 d
} t_flag;

int parse(t_flag *tk, char **str, va_list ap);
void print_flag(t_flag *tk);

#endif
