/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:35:18 by ycha              #+#    #+#             */
/*   Updated: 2021/03/08 15:50:19 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen(long long int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n == -9223372036854775807)
		return (11);
	i = n < 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static char	*putstr(char *ptr, const char *s, int len)
{
	while (len--)
		*ptr++ = *s++;
	return (ptr);
}

static char	*putend(char *ret, char *ptr)
{
	putstr(ptr, "\0", 1);
	return (ret);
}

static char	*rec(char *ptr, long long int n, int len, char *base)
{
	if (n == 0)
		return (ptr);
	ptr = rec(ptr, n / len, len, base);
	return (putstr(ptr, base + (n % len), 1));
}

char		*ft_itoa_base(long long int n, char *base)
{
	int		base_len;
	char	*ret;
	char	*ptr;

	base_len = ft_strlen(base);
	if (!(ret = malloc(getlen(n) + 1)))
		return (0);
	ptr = ret;
	if (n == -9223372036854775807)
	{
		ptr = putstr(ptr, "-", 1);
		ptr = rec(ptr, n / -base_len, base_len, base);
		ptr = putstr(ptr, base - n % base_len, 1);
		return (putend(ret, ptr));
	}
	if (n < 0)
	{
		ptr = putstr(ptr, "-", 1);
		n *= -1;
	}
	ptr = rec(ptr, n, base_len, base);
	return (putend(ret, ptr));
}
