#include "engine.h"

int		sl_pow(int base, int exp)
{
	if (exp == 0)
		return (1);
	return (base * sl_pow(base, exp -1));
}

int		sl_rev_atoi(char *str)
{
	int	n;
	int	idx;
	int	result;

	n = 0;
	result = 0;
	idx = strlen(str) - 1;
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
	fd = open("./dashboard.rnk", O_RDONLY, 0777);
	if (fd == -1)
		return ;
	if (read(fd, &buf, 1000) == -1)
		return ;
	split = sl_split(buf, '\n');
	close(fd);

	// 2. file write (O_TRUNC 해서 기존 파일 지워버림)
	fd = open("./dashboard.rnk", O_WRONLY | O_TRUNC, 0777);
	idx = -1;
	s_step = sl_itoa(step);
	s_deathcount = sl_itoa(deathcount);
	while (split[++idx])
	{
		if (cmp_rank(split[idx], deathcount))
		{
			write(fd, userid, sl_strlen(userid));
			write(fd, " ", 1);
			write(fd, s_step, sl_strlen(s_step));
			write(fd, " ", 1);
			write(fd, s_deathcount, sl_strlen(s_deathcount));
		}
		else
			write(fd, split[idx], sl_strlen(split[idx]));
	}
	free(s_step);
	free(s_deathcount);
	sl_free_split(split);
	close(fd);
}

