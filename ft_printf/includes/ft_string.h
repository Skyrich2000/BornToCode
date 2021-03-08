/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 11:20:43 by ycha              #+#    #+#             */
/*   Updated: 2021/03/04 10:45:17 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

int ft_print(char *str);
char *ft_strdup_x(const char *start, const char *end);
char *ft_strchr_x(const char *s, int c);
char *ft_itoa_base(long long int n, char *base);
char *ft_itoa_base_unsigned(unsigned long long int n, char *base);

#endif
