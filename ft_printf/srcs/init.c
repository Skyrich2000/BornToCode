/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 17:16:19 by ycha              #+#    #+#             */
/*   Updated: 2021/03/08 12:15:27 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "build.h"
#include "parse.h"
#include "libft.h"

//void init_parse() {
//	ft_memcpy(g_parse_lengths[0], "ll", 3);
//	ft_memcpy(g_parse_lengths[1], "hh", 3);
//	ft_memcpy(g_parse_lengths[2], "l", 2);
//	ft_memcpy(g_parse_lengths[3], "h", 2);
//}

void init_print_arg() {
	// 123456789
	// %cspdiuxX
	print_arg[2] = print_char;
	print_arg[3] = print_string;
	print_arg[4] = print_number;
	print_arg[5] = print_number;
	print_arg[6] = print_number;
	print_arg[7] = print_number;
	print_arg[8] = print_number;
	print_arg[9] = print_number;
}

void init_get_arg() {
	// 12345678910
	// %cspdiuxXf
	get_arg[2] = get_int;
	get_arg[3] = get_pointer;
	get_arg[4] = get_pointer;
	get_arg[5] = get_int;
	get_arg[6] = get_int;
	get_arg[7] = get_unsigned_int;
	get_arg[8] = get_unsigned_int;
	get_arg[9] = get_unsigned_int;
}

void init() {
	init_get_arg();
	init_print_arg();
}
