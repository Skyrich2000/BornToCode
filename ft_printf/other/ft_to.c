/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:01:11 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/08 21:48:13 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int		check_over_range(unsigned long long num, int sign)
{
	if (num > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (num > LLONG_MAX && sign == 1)
		return (-1);
	return (num * sign);
}

int				ft_atoi_double(const char **nptr)
{
	int					i;
	int					sign;
	long long			num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(**nptr))
		*nptr += 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign *= -1;
		i++;
	}
	while (**nptr >= '0' && **nptr <= '9')
	{
		num *= 10;
		num += (*(*nptr)++ - '0');
	}
	return (check_over_range(num, sign));
}

int				get_len_base(long long n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char			*ft_uitoa_base(unsigned int n, char *base)
{
	long long	num;
	char		*str;
	long long	base_len;
	int			len;

	num = n;
	base_len = ft_strlen(base);
	len = get_len_base(num, base_len);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (num > 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}

char			*ft_ultoa_base(unsigned long n, char *base)
{
	long long	num;
	char		*str;
	long long	base_len;
	int			len;

	num = n;
	base_len = ft_strlen(base);
	len = get_len_base(num, base_len);
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	if (num == 0)
		str[0] = '0';
	str[len--] = 0;
	while (num > 0)
	{
		str[len--] = base[num % base_len];
		num /= base_len;
	}
	return (str);
}
