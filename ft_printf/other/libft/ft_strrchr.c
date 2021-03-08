/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:59:04 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/24 16:50:08 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_c;

	last_c = 0;
	while (*s)
	{
		if (*s == c)
			last_c = (char *)s;
		s++;
	}
	return (!c ? (char *)s : last_c);
}
