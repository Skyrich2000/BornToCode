#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int		sl_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

static int	getlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	i = n < 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

static char	*putstr(char *ptr, const char *s, int len)
{
	while (len--)
		*ptr++ = *s++;
	return (ptr);
}

static char	*putend(char *ret, char *ptr)
{
	putstr(ptr, "\0", 1);
	return (ret);
}

static char	*rev(char *ptr, int n)
{
	char	c;

	if (n == 0)
		return (ptr);
	c = '0' + n % 10;
	ptr = rev(ptr, n / 10);
	return (putstr(ptr, &c, 1));
}

char		*sl_itoa(int n)
{
	char	*ret;
	char	*ptr;

	if (!(ret = malloc(getlen(n) + 1)))
		return (0);
	ptr = ret;
	if (n == 0)
	{
		ptr = putstr(ptr, "0", 1);
		return (putend(ret, ptr));
	}
	if (n == -2147483648)
	{
		ptr = putstr(ptr, "-2147483648", 11);
		return (putend(ret, ptr));
	}
	if (n < 0)
	{
		ptr = putstr(ptr, "-", 1);
		n *= -1;
	}
	ptr = rev(ptr, n);
	return (putend(ret, ptr));
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

char	**sl_split(char *s, char c)
{
	char	**ret;
	char	*from;
	int		i;

	ret = (char **)malloc((sl_check_size(s, c) + 1) * sizeof(char *));
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

int		sl_pow(int base, int exp)
{
	if (exp == 0)
		return (1);
	return (base * sl_pow(base, exp - 1));
}

int		sl_rev_atoi(char *str)
{
	int	n;
	int	idx;
	int	result;

	n = 0;
	result = 0;
	idx = sl_strlen(str) - 1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result += (str[idx] - '0') * sl_pow(10, n);
		--idx;
		++n;
	}
	return (result);
}

int	cmp_rank(char *org, int new)
{
	return (sl_rev_atoi(org) > new);
}

void	result(char *userid, int step, int deathcount)
{
	int fd;
	int idx;
	char buf[1000]; // 처음에 rank file read 해오는 버퍼
	char **split;	// buf를 '\n' 기준으로 split
	char *s_step;	// step을 string으로 바꿔줌(write하려고)
	char *s_deathcount;	// deathcount를 string으로 바꿔줌

	// 1. file read
	fd = open("./dashboard.rnk", O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
		return ;
	if (read(fd, &buf, 1000) == -1)
		return ;
	split = sl_split(buf, '\n');
	printf("-> %s\n", split[0]);
	close(fd);

	// 2. file write (O_TRUNC 해서 기존 파일 지워버림)
	fd = open("./dashboard.rnk", O_WRONLY | O_TRUNC, 0777);
	idx = -1;
	s_step = sl_itoa(step);
	s_deathcount = sl_itoa(deathcount);
	if (!*split)
	{
		write(fd, userid, sl_strlen(userid));
		write(fd, " ", 1);
		write(fd, s_step, sl_strlen(s_step));
		write(fd, " ", 1);
		write(fd, s_deathcount, sl_strlen(s_deathcount));
	}
	else
	{
		while (++idx < sl_check_size(buf, '\n'))
		{
			printf("-> %d : ", idx);
		 	if (cmp_rank(split[idx], deathcount))
			{
				printf("if\n");
				write(fd, userid, sl_strlen(userid));
				write(fd, " ", 1);
				write(fd, s_step, sl_strlen(s_step));
				write(fd, " ", 1);
				write(fd, s_deathcount, sl_strlen(s_deathcount));
				write(fd, "\n", 1);
			}
			printf("else\n");
			write(fd, split[idx], sl_strlen(split[idx]));
			write(fd, "\n", 1);
		}

	}
	free(s_step);
	free(s_deathcount);
	sl_free_split(split);
	close(fd);
}

int main(void)
{
	result("suhsihn", 1000, 0);
	result("ycha", 2000, 1);
}
