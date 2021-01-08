/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 23:24:38 by ycha              #+#    #+#             */
/*   Updated: 2021/01/08 16:07:12 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	char	*ptr;
	int		len;
	int		i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!(ret = malloc(len + 1)))
		return (0);
	ptr = ret;
	i = 0;
	while (i < len)
		*ptr++ = f(i++, *s++);
	*ptr = 0;
	return (ret);
}
