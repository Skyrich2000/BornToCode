/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:06:16 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:06:20 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_BONUS_H
# define LIB_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int			sl_abs(int a);
void		sl_bzero(void *s, int n);
void		*sl_memcpy(void *dest, const void *src, size_t n);

int			sl_strlen(char *s);
char		*ft_strchr(const char *s, int c);
char		*sl_strjoin(char *s1, char *s2);
size_t		sl_strlcpy(char *dst, char *src, size_t dstsize);

int			sl_atoi(const char *str);
char		*sl_itoa(int n);
int			sl_rev_atoi(char *str);

char		**sl_split(char *s, char c);
int			sl_check_size(char *s, char c);
int			sl_split_size(char **split);
char		**sl_free_split(char **s);

void		sl_exit(int errno);
void		sl_free(void *data);
void		sl_free_arr3(char *str[3]);
void		sl_free_arr5(char *str[5]);

#endif
