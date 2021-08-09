/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/08/06 03:45:07 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int			sl_strlen(char *s);
char		*sl_strjoin(char *s1, char *s2);
char		*sl_itoa(int n);
void		*sl_memcpy(void *dest, const void *src, size_t n);
void		sl_bzero(void *s, int n);
void		sl_free(void *data);
char		**sl_free_split(char **s);
char		**sl_split(char *s, char c);
int			sl_rev_atoi(char *str);
int			sl_check_size(char *s, char c);
int			sl_split_size(char **split);
char		*ft_strchr(const char *s, int c);
int			sl_atoi(const char *str);
void		sl_exit(int errno);
int			sl_abs(int a);
size_t      sl_strlcpy(char *dst, char *src, size_t dstsize);

#endif
