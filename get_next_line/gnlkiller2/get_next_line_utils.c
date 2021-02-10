/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:46:57 by ycha              #+#    #+#             */
/*   Updated: 2021/02/10 02:07:28 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t  ft_strlen(const char *s)
{
        size_t  len;

        len = 0;
        while (*s++)
                len++;
        return (len);
}


static char     *ft_strcpy(char *dest, char *src)
{
        char    *temp;

        temp = dest;
        while ((*dest++ = *src++))
                ;
        return (temp);
}

char            *ft_strdup(const char *s)
{
        int             len;
        char    *ret;
        char    *src;

        src = (char *)s;
        len = ft_strlen(src);
        ret = (char *)malloc(len + 1);
        if (!ret)
                return (0);
        return (ft_strcpy(ret, src));
}
