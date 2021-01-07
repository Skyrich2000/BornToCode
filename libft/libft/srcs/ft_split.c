/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 01:45:23 by ycha              #+#    #+#             */
/*   Updated: 2021/01/07 09:30:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	get_word_num(char const *s, char c)
{
	int	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
				++s;
			++num;
		}
		else
			++s;
	}
	return (num);
}

static char	*strdup_p(char *start, char *end)
{
	char	*ret;
	char	*ptr;

	if (!(ret = malloc(end - start + 1)))
		return (0);
	ptr = ret;
	while (start != end)
		*ptr++ = *start++;
	*ptr = 0;
	return (ret);
}

char		**ft_split(char const *s, char c)
{
	char	*start;
	char	**ret;
	char	**ptr;

	if (!s)
		return (0);
	if (!(ret = malloc((get_word_num(s, c) + 1) * sizeof(char *))))
		return (0);
	ptr = ret;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				++s;
			*ptr = strdup_p(start, (char *)s);
			++ptr;
		}
		else
			++s;
	}
	*ptr = 0;
	return (ret);
}
