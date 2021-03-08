/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 12:12:32 by ycha              #+#    #+#             */
/*   Updated: 2021/03/06 01:28:10 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char *ft_strdup_x(const char *start, const char *end) {
	char *ret;

	if(!(ret = malloc(end - start + 1)))
		return (0);
	ft_memcpy(ret, start, end - start);
	ret[end - start] = 0;
	return (ret);
}

char    *ft_strchr_x(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

