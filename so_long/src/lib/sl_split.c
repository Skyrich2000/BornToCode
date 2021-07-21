#include "engine.h"

size_t	sl_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize)
	{
		while (i < dstsize - 1 && src[i])
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	while (src[i])
		++i;
	return (i);
}


char	*sl_substr(char *s, unsigned int start, size_t len)
{
	char	*dest;

	dest = (char *)malloc(len + 1);
	if (!s || !dest)
		return (NULL);
	if ((int)start >= sl_strlen(s)
		|| !(sl_strlcpy(dest, s + start, len + 1)))
		dest[0] = '\0';
	return (dest);
}

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
