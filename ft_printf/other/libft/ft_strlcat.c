/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:04:08 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/22 21:13:06 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		d;
	int		s;
	size_t	cnt;

	d = 0;
	s = 0;
	cnt = 0;
	while (dst[d] && cnt < dstsize)
	{
		d++;
		cnt++;
	}
	while (src[s] && cnt + 1 < dstsize)
	{
		dst[d++] = src[s++];
		cnt++;
	}
	if (cnt < dstsize)
		dst[d] = 0;
	while (src[s])
	{
		s++;
		cnt++;
	}
	return (cnt);
}
