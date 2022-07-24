/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:35:18 by ycha              #+#    #+#             */
/*   Updated: 2021/01/08 16:07:04 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_get_number_len(unsigned long long n, int len)
{
	int	i;

	i = 1;
	n /= len;
	while (n > 0)
	{
		n /= len;
		++i;
	}
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
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

char	*rt_strchr(const char *s, int c)
{
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

char	*ft_strdup(const char *s)
{
	int		len;
	char	*ret;
	char	*src;

	if (s == 0)
		return (0);
	src = (char *)s;
	len = ft_strlen(src);
	ret = (char *)malloc(len + 1);
	if (!ret)
		return (0);
	return (ft_memcpy(ret, src, len + 1));
}
