/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:14:09 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/26 11:13:53 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	while (n)
	{
		*((unsigned char *)dest) = *((unsigned char *)src);
		if (*(unsigned char *)dest++ == (unsigned char)c)
			break ;
		src++;
		n--;
	}
	if (n == 0)
		return (0);
	return (dest);
}
