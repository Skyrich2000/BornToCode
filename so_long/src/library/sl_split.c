#include "engine.h"

static int	sl_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

static size_t	sl_check_size(char *s, char c)
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

	ret = (char **)sl_calloc((sl_check_size(s, c) + 1), sizeof(char *));
	if (!s || !ret)
		return (NULL);
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
