/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:46:57 by ycha              #+#    #+#             */
/*   Updated: 2021/02/11 10:11:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int  ft_strlen(char *s)
{
        int  len;

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
        int  d_len;
        int  s_len;

        d_ptr = dest;
        s_ptr = src;
        while (size && *dest)
        {
                --size;
                ++dest;
        }
        while (*src)
                ++src;
        d_len = dest - d_ptr;
        s_len = src - s_ptr;
        if (size <= 0)
                return (d_len + s_len);
        while (*s_ptr && size-- > 1)
                *dest++ = *s_ptr++;
        *dest = 0;
        return (d_len + s_len);
}

void    ft_bzero(void *s, int n)
{
        char    *ptr;

        ptr = (char *)s;
        while (n--)
        {
                *ptr = 0;
                ptr++;
        }
}

char    *ft_strnjoin(char *s1, char *s2, int m)
{
		int		n;
        char    *ret;

		printf("strnjoin {%p %p %d}\n", s1, s2, m);
		n = ft_strlen(s1);
        if (!(ret = (char *)malloc(n + m + 1)))
			return (0);
		ft_bzero(ret, n + m + 1);
        if (s1)
			ft_strlcat(ret, s1, n + 1);
		if (s2)
			ft_strlcat(ret, s2, n + m + 1);
        return (ret);
}


