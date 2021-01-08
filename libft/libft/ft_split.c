/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 01:45:23 by ycha              #+#    #+#             */
/*   Updated: 2021/01/08 20:24:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	**free_all(char **ret)
{
	while (*ret)
	{
		free(*ret);
		++ret;
	}
	free(ret);
	return (0);
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
			if (!(*ptr = strdup_p(start, (char *)s)))
				return (free_all(ret));
			++ptr;
		}
		else
			++s;
	}
	*ptr = 0;
	return (ret);
}
#include <stdio.h>
int	main(void)
{
	char **ret = ft_split("abc abc qwe asd", ' ');
	int	i = 0;
	while(ret[i])
	{
		printf("%s\n", ret[i]);
		i++;
	}
	while(1)
		;
	return (0);
}

