#include "push_swap.h"

static int	get_word_num(char *s, char c)
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

	ret = malloc(end - start + 1);
	if (!ret)
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

char	**ft_split(char *s, char c)
{
	char	*start;
	char	**ret;
	char	**ptr;

	if (!s)
		return (0);
	ret = malloc((get_word_num(s, c) + 1) * sizeof(char *));
	if (!ret)
		return (0);
	ptr = ret;
	while (*s++)
	{
		if (*(s - 1) != c)
		{
			start = (char *)--s;
			while (*s && *s != c)
				++s;
			*ptr = strdup_p(start, (char *)s);
			if (!*ptr)
				return (free_all(ret));
			++ptr;
		}
	}
	*ptr = 0;
	return (ret);
}
