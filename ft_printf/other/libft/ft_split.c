/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 23:40:16 by jiwchoi           #+#    #+#             */
/*   Updated: 2020/12/29 17:32:20 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_word_cnt(char const *s, char c)
{
	int		cnt;

	cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			cnt++;
			while (*s && *s != c)
				s++;
		}
		s++;
	}
	return (cnt);
}

static int			get_sep_word(char **arr, char const *s, char sep)
{
	int		i;
	int		len;
	char	*start;

	i = 0;
	len = 0;
	while (*s)
	{
		if (!len && *s != sep)
			start = (char *)s;
		if (len && *s == sep)
		{
			arr[i] = ft_substr(start, 0, len);
			if (!arr[i++])
				return (i);
			len = 0;
		}
		if (*s != sep)
			len++;
		s++;
	}
	if (len)
		arr[i++] = ft_substr(start, 0, len);
	arr[i] = 0;
	return (0);
}

char				**ft_split(char const *s, char c)
{
	int		i;
	int		idx;
	char	**result;

	if (!s)
		return (0);
	if (!(result = (char **)malloc(sizeof(char *) * (ft_word_cnt(s, c) + 1))))
		return (0);
	idx = get_sep_word(result, s, c);
	if (idx)
	{
		i = 0;
		while (i < idx - 1)
			free(result[i]);
		free(result);
		result = NULL;
	}
	return (result);
}
