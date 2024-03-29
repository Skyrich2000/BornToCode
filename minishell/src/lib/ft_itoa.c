/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:00 by echung            #+#    #+#             */
/*   Updated: 2021/01/28 21:43:58 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int			len;
	long long	n_temp;

	len = 0;
	if (n == 0)
		return (1);
	n_temp = n;
	if (n_temp < 0)
		n_temp = -1 * n_temp * 10;
	while (n_temp > 0)
	{
		n_temp = n_temp / 10;
		len++;
	}
	return (len);
}

static int	ft_power(int n)
{
	int	result;

	result = 1;
	while (n > 0)
	{
		result = result * 10;
		n--;
	}
	return (result);
}

char	*_ft_itoa(int n, int n_org, int len)
{
	char	*ascii;
	char	*ascii_org;

	ascii = malloc(sizeof(char) * (len + 1));
	if (!ascii)
		return (0);
	ascii_org = ascii;
	ascii[len] = '\0';
	if (n_org < 0)
	{
		*ascii++ = '-';
		n = -1 * n;
		len = len - 1;
	}
	while (len > 0)
	{
		*ascii = n / ft_power(len - 1) + '0';
		n = n - ((*ascii++ - '0') * ft_power(len-- - 1));
	}
	return (ascii_org);
}

char	*ft_itoa(int n)
{
	int		len;
	int		n_org;

	n_org = n;
	if (n_org == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen(n);
	return (_ft_itoa(n, n_org, len));
}
