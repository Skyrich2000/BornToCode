/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 15:51:27 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/28 23:03:05 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isset(char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	char	*res;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i] && ft_isset(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	while (i >= start && ft_isset(s1[i], set))
		i--;
	if (!(res = ft_substr(s1, start, i - start + 1)))
		return (0);
	return (res);
}
