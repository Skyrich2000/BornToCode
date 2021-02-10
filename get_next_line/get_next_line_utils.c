/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:46:57 by ycha              #+#    #+#             */
/*   Updated: 2021/02/10 19:11:40 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int  ft_strlen(char *s)
{
        size_t  len;

        len = 0;
		if (!s)
			return (0);
        while (*s++)
                len++;
        return (len);
}


char    *ft_strchr(char *s, int c)
{
		if (!s)
			return (0);
        while (*s)
        {
                if (*s == c)
                        return ((char *)s);
                s++;
        }
        if (*s == c)
                return ((char *)s);
        return (0);
}

int  ft_strlcat(char *dest, char *src, int size)
{
        char    *d_ptr;
        char    *s_ptr;
        size_t  d_len;
        size_t  s_len;

        d_ptr = dest;
        s_ptr = src;
        while (size && *dest)
        {
                --size;
                ++dest;
        }
        while (*src)
                ++src;
        d_len = (size_t)(dest - d_ptr);
        s_len = (size_t)(src - s_ptr);
        if (size <= 0)
                return (d_len + s_len);
        while (*s_ptr && size-- > 1)
                *dest++ = *s_ptr++;
        *dest = 0;
        return (d_len + s_len);
}

