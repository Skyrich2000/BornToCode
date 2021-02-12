/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:46:57 by ycha              #+#    #+#             */
/*   Updated: 2021/02/12 14:45:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*temp;

	if (src == 0 && dest == 0)
		return (0);
	temp = dest;
	while (n--)
		*(char *)dest++ = *(char *)src++;
	return (temp);
}

void	ft_bzero(void *s, int n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}

char	*ft_strnjoin(char *s1, char *s2, int m)
{
	int		n;
	char	*ret;

	n = ft_strlen(s1);
	if (!(ret = (char *)malloc(n + m + 1)))
		return (0);
	ft_bzero(ret, n + m + 1);
	if (s1)
		ft_memcpy(ret, s1, n);
	if (s2)
		ft_memcpy(ret + n, s2, m);
	ret[n + m] = 0;
	return (ret);
}
