/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 20:01:39 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/24 20:09:58 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*d;

	if (!dest && !src)
		return (0);
	d = dest;
	while (n--)
		*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (d);
}
