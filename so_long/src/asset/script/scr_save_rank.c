#include "engine.h"

int		cmp_rank(char *org, int new)
{
	return (sl_rev_atoi(org) > new);
}

void	scr_save_rank(char *name, int time, int deathcount)
{
	int fd;
	int idx;
	int flag;
	char buf[BUFFER_SIZE]; // 처음에 rank file read 해오는 버퍼
	char **split;	// buf를 '\n' 기준으로 split
	char *s_step;	// step을 string으로 바꿔줌(write하려고)
	char *s_deathcount;	// deathcount를 string으로 바꿔줌

	// 1. file read
	sl_bzero(buf, BUFFER_SIZE);
	fd = open("./dashboard.rnk", O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
		return ;
	if (read(fd, &buf, BUFFER_SIZE) == -1)
		return ;
	split = sl_split(buf, '\n');
	close(fd);

	// 2. file write (O_TRUNC 해서 기존 파일 지워버림)
	fd = open("./dashboard.rnk", O_WRONLY | O_TRUNC, 0777);
	idx = -1;
	s_step = sl_itoa(time);
	s_deathcount = sl_itoa(deathcount);
	if (!*split)
	{
		write(fd, name, sl_strlen(name));
		write(fd, "           ", 11 - sl_strlen(name));
		write(fd, s_step, sl_strlen(s_step));
		write(fd, "  ", 2);
		write(fd, s_deathcount, sl_strlen(s_deathcount));
		write(fd, "\n", 1);
	}
	else
	{
		flag = 0;
		while (++idx < sl_split_size(split))
		{
			if (!flag && cmp_rank(split[idx], deathcount))
			{
				write(fd, name, sl_strlen(name));
				write(fd, "           ", 11 - sl_strlen(name));
				write(fd, s_step, sl_strlen(s_step));
				write(fd, "  ", 2);
				write(fd, s_deathcount, sl_strlen(s_deathcount));
				write(fd, "\n", 1);
				flag = 1;
			}
			write(fd, split[idx], sl_strlen(split[idx]));
			write(fd, "\n", 1);
		}
		if (!flag)
		{
			write(fd, name, sl_strlen(name));
			write(fd, "           ", 11 - sl_strlen(name));
			write(fd, s_step, sl_strlen(s_step));
			write(fd, "  ", 2);
			write(fd, s_deathcount, sl_strlen(s_deathcount));
			write(fd, "\n", 1);
			flag = 1;
		}
	}
	free(s_step);
	free(s_deathcount);
	sl_free_split(split);
	close(fd);
}

