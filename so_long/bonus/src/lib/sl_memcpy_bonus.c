/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:22:34 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:08:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

void	*sl_memcpy(void *dest, const void *src, size_t n)
{
	void	*temp;

	if (src == 0 && dest == 0)
		return (0);
	temp = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (temp);
}
