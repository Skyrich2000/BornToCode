/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 00:39:27 by ycha              #+#    #+#             */
/*   Updated: 2021/01/08 16:05:50 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (s == 0)
		return (0);
	len = ft_strlen(s) <= start ? 0 : len;
	if (!(ret = (char *)malloc(len + 1)))
		return (0);
	ft_strlcpy(ret, (char *)s + start, len + 1);
	return (ret);
}
