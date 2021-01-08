/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:19:09 by ycha              #+#    #+#             */
/*   Updated: 2021/01/08 02:22:11 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	char	*d_ptr;
	char	*s_ptr;
	size_t	d_len;
	size_t	s_len;

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
