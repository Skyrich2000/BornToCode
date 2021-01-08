/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:21:13 by ycha              #+#    #+#             */
/*   Updated: 2021/01/07 09:34:02 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == 0)
		return (0);
	if (size > 0)
	{
		while (i < size - 1 && (*dest = *src))
		{
			++dest;
			++src;
			++i;
		}
		*dest = '\0';
	}
	while (*src++)
		++i;
	return (i);
}
