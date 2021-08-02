/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:22:34 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 03:03:40 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int		sl_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

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

void	sl_bzero(void *s, int n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}

char	*sl_strjoin(char *s1, char *s2)
{
	int		n;
	int		m;
	char	*ret;

	n = sl_strlen(s1);
	m = sl_strlen(s2);
	if (!(ret = (char *)malloc(n + m + 1)))
		sl_exit(12);
	sl_bzero(ret, n + m + 1);
	if (s1)
		sl_memcpy(ret, s1, n);
	if (s2)
		sl_memcpy(ret + n, s2, m);
	ret[n + m] = 0;
	return (ret);
}
