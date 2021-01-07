/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:22:34 by ycha              #+#    #+#             */
/*   Updated: 2021/01/03 00:42:27 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	if (s1 == 0 || s2 == 0)
		return (0);
	if (!(ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	ft_strlcpy(ret, (char *)s1, ft_strlen(s1) + 1);
	ft_strlcat(ret, (char *)s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (ret);
}
