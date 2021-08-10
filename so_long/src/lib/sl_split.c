/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:35:18 by ycha              #+#    #+#             */
/*   Updated: 2021/08/10 16:19:33 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*sl_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;

	dest = (char *)malloc(len + 1);
	if (!s || !dest)
		sl_exit(12);
	if ((int)start >= sl_strlen(s)
		|| !(sl_strlcpy(dest, s + start, len + 1)))
		dest[0] = '\0';
	return (dest);
}

int	sl_split_size(char **split)
{
	int	i;

	i = -1;
	if (!split)
		return (0);
	while (split[++i])
		;
	return (i);
}

int	sl_check_size(char *s, char c)
{
	size_t	cnt;
	int		i;

	cnt = 0;
	i = -1;
	if (!s)
		return (0);
	while (*(++i + s + 1))
		if (*(i + s) != c && *(i + s + 1) == c)
			++cnt;
	if (*(s + i) != c)
		return (cnt + 1);
	return (cnt);
}

char	**sl_free_split(char **s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!*s)
	{
		free(s);
		s = 0;
		return (NULL);
	}
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	s = 0;
	return (NULL);
}

char	**sl_split(char *s, char c)
{
	char	**ret;
	char	*from;
	int		i;

	ret = malloc((sl_check_size(s, c) + 1) * sizeof(char *));
	if (!s || !ret)
		sl_exit(12);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			from = (char *)s;
			while (*s && *s != c)
				++s;
			ret[i++] = sl_substr(from, 0, (s - from));
			if (!ret)
				return (sl_free_split(ret));
		}
		else
			++s;
	}
	ret[i] = NULL;
	return (ret);
}
