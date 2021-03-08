/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:07:28 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/09 20:40:49 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_join_precision(t_flag *flag, char *src)
{
	int		len;
	char	*tmp;
	char	*result;

	len = flag->precision - ft_strlen(src);
	if (src[0] == '-')
		len += 1;
	if (len > 0)
	{
		tmp = malloc(len + 1);
		ft_memset(tmp, '0', len);
		tmp[len] = 0;
		if (src[0] == '-')
		{
			tmp[0] = '-';
			src[0] = '0';
		}
		result = ft_strjoin(tmp, src);
		free(tmp);
	}
	else
		result = ft_strdup(src);
	return (result);
}

char	*ft_join_width(t_flag *flag, char *src)
{
	int		len;
	char	*tmp;
	char	*result;

	len = flag->width - ft_strlen(src);
	if (len > 0)
	{
		tmp = malloc(len + 1);
		ft_memset(tmp, flag->padding, len);
		tmp[len] = 0;
		if (src[0] == '-' && tmp[0] == '0')
		{
			tmp[0] = '-';
			src[0] = '0';
		}
		if (flag->left)
			result = ft_strjoin(src, tmp);
		else
			result = ft_strjoin(tmp, src);
		free(tmp);
	}
	else
		result = ft_strdup(src);
	return (result);
}
