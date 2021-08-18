/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 23:22:34 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:27:25 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

char	*sl_strjoin(char *s1, char *s2)
{
	int		n;
	int		m;
	char	*ret;

	n = sl_strlen(s1);
	m = sl_strlen(s2);
	ret = (char *)malloc(n + m + 1);
	if (!ret)
		sl_exit(12);
	sl_bzero(ret, n + m + 1);
	if (s1)
		sl_memcpy(ret, s1, n);
	if (s2)
		sl_memcpy(ret + n, s2, m);
	ret[n + m] = 0;
	return (ret);
}
