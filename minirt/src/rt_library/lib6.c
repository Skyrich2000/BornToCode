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

static int	getlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n == -2147483648)
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

static char	*rev(char *ptr, int n)
{
	char	c;

	if (n == 0)
		return (ptr);
	c = '0' + n % 10;
	ptr = rev(ptr, n / 10);
	return (putstr(ptr, &c, 1));
}

char		*ft_itoa(int n)
{
	char	*ret;
	char	*ptr;

	if (!(ret = malloc(getlen(n) + 1)))
		return (0);
	ptr = ret;
	if (n == 0)
	{
		ptr = putstr(ptr, "0", 1);
		return (putend(ret, ptr));
	}
	if (n == -2147483648)
	{
		ptr = putstr(ptr, "-2147483648", 11);
		return (putend(ret, ptr));
	}
	if (n < 0)
	{
		ptr = putstr(ptr, "-", 1);
		n *= -1;
	}
	ptr = rev(ptr, n);
	return (putend(ret, ptr));
}