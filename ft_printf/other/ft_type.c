/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:20:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/10 13:08:26 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_num(va_list ap, t_flag *flag, char type)
{
	char	*src;
	char	*result;
	int		cnt;
	int		num;

	src = 0;
	if (flag->dot && flag->precision >= 0)
		flag->padding = ' ';
	num = va_arg(ap, int);
	if (flag->dot && flag->precision == 0 && num == 0)
		src = ft_strdup("");
	else
	{
		if (type == 'd' || type == 'i')
			src = ft_itoa(num);
		else if (type == 'u')
			src = ft_uitoa_base(num, "0123456789");
		else if (type == 'x')
			src = ft_uitoa_base(num, "0123456789abcdef");
		else if (type == 'X')
			src = ft_uitoa_base(num, "0123456789ABCDEF");
	}
	result = ft_join_precision(flag, src);
	free(src);
	src = ft_strdup(result);
	free(result);
	result = ft_join_width(flag, src);
	free(src);
	ft_putstr_fd(result, 1);
	cnt = ft_strlen(result);
	free(result);
	return (cnt);
}

int		ft_type_address(va_list ap, t_flag *flag)
{
	char			*src;
	char			*result;
	int				cnt;
	unsigned long	num;

	num = va_arg(ap, unsigned long);
	if (flag->dot && flag->precision == 0 && num == 0)
		src = ft_strdup("");
	else
		src = ft_ultoa_base(num, "0123456789abcdef");
	result = ft_strjoin("0x", src);
	free(src);
	src = ft_strdup(result);
	free(result);
	result = ft_join_width(flag, src);
	free(src);
	ft_putstr_fd(result, 1);
	cnt = ft_strlen(result);
	free(result);
	return (cnt);
}

int		ft_type_char(va_list ap, t_flag *flag, char type)
{
	char	*src;
	char	*result;
	int		cnt;
	int		is_null;

	is_null = 0;
	src = malloc(2);
	src[1] = 0;
	if (type == 'c')
		src[0] = va_arg(ap, int);
	else if (type == '%')
		src[0] = '%';
	if (!src[0])
		is_null = 1;
	result = ft_join_width(flag, src);
	free(src);
	cnt = ft_strlen(result);
	if (is_null && cnt == flag->width)
	{
		result[cnt - 1] = 0;
		if (cnt == 0)
			cnt++;
	}
	if (is_null && flag->left)
	{
		ft_putchar_fd('\0', 1);
		ft_putstr_fd(result, 1);
	}
	else if (is_null)
	{
		ft_putstr_fd(result, 1);
		ft_putchar_fd('\0', 1);
	}
	else
		ft_putstr_fd(result, 1);
	free(result);
	return (cnt);
}

int		ft_type_str(va_list ap, t_flag *flag)
{
	char	*src;
	char	*result;
	int		cnt;
	char	*tmp;

	tmp = va_arg(ap, char *);
	if (!tmp)
		src = ft_strdup("(null)");
	else
		src = ft_strdup(tmp);
	if (flag->dot && flag->precision >= 0)
	{
		tmp = ft_substr(src, 0, flag->precision);
		free(src);
		src = ft_strdup(tmp);
		free(tmp);
	}
	result = ft_join_width(flag, src);
	free(src);
	ft_putstr_fd(result, 1);
	cnt = ft_strlen(result);
	free(result);
	return (cnt);
}
