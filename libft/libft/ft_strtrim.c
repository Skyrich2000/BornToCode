/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 08:39:29 by ycha              #+#    #+#             */
/*   Updated: 2021/01/07 09:30:17 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_inset(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static char	*find_front(char const *s, char const *set)
{
	while (*s)
	{
		if (!is_inset(*s, set))
			break ;
		++s;
	}
	return ((char *)s);
}

static char	*find_end(char const *s, char const *set)
{
	char	*start;

	start = (char *)s;
	while (*s)
		s++;
	while (s != start)
	{
		if (!is_inset(*(s - 1), set))
			break ;
		--s;
	}
	return ((char *)s);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	char	*ptr;
	char	*start;
	char	*end;

	if (!s1)
		return (0);
	start = find_front(s1, set);
	end = find_end(s1, set);
	if (!(ret = malloc(start < end ? end - start + 1 : 1)))
		return (0);
	ptr = ret;
	while (start < end)
		*ptr++ = *start++;
	*ptr = '\0';
	return (ret);
}
