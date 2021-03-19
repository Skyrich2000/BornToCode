/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 18:52:36 by ycha              #+#    #+#             */
/*   Updated: 2021/01/08 16:05:42 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	char	*temp;

	temp = dest;
	while ((*dest++ = *src++))
		;
	return (temp);
}

char		*ft_strdup(const char *s)
{
	int		len;
	char	*ret;
	char	*src;

	src = (char *)s;
	len = ft_strlen(src);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	return (ft_strcpy(ret, src));
}
