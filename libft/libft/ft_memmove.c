/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:01:32 by ycha              #+#    #+#             */
/*   Updated: 2021/01/07 09:35:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		dir;
	void	*temp;

	dir = 1;
	temp = dest;
	if (src == 0 && dest == 0)
		return (0);
	if (src < dest)
	{
		src = src + n - 1;
		dest = dest + n - 1;
		dir = -1;
	}
	while (n--)
	{
		*(char *)dest = *(char *)src;
		src += dir;
		dest += dir;
	}
	return (temp);
}
