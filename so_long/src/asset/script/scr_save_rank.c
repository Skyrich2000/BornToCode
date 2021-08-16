/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_save_rank.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:16:08 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:16:09 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

static int	cmp_rank(char *org, int time, int deathcount)
{
	char	**split;
	int		cmp_time;
	int		cmp_deathcount;

	split = sl_split(org, ' ');
	cmp_time = sl_atoi(split[1]);
	cmp_deathcount = sl_atoi(split[2]);
	sl_free_split(split);
	if (cmp_deathcount > deathcount)
		return (1);
	else if (cmp_deathcount == deathcount)
		return (cmp_time > time);
	else
		return (0);
}

static int	write_record(int fd, char *name, char *time, char *deathcount)
{
	write(fd, name, sl_strlen(name));
	write(fd, "           ", 11 - sl_strlen(name));
	write(fd, time, sl_strlen(time));
	write(fd, "  ", 2);
	write(fd, deathcount, sl_strlen(deathcount));
	write(fd, "\n", 1);
	return (1);
}

static char	**file_read(char *name)
{
	int		fd;
	char	buf[BUFFER_SIZE];

	sl_bzero(buf, BUFFER_SIZE);
	fd = open(name, O_RDONLY | O_CREAT, 0777);
	if (fd == -1)
		return (NULL);
	if (read(fd, &buf, BUFFER_SIZE) == -1)
		return (NULL);
	close(fd);
	return (sl_split(buf, '\n'));
}

void	scr_save_rank(char *name, int time, int deathcount)
{
	int		fd;
	int		idx;
	int		flag;
	char	**split;
	char	*str[2];

	split = file_read("./res/dashboard.rnk");
	fd = open("./res/dashboard.rnk", O_WRONLY | O_TRUNC, 0777);
	idx = -1;
	str[0] = sl_itoa(time);
	str[1] = sl_itoa(deathcount);
	flag = 0;
	while (++idx < sl_split_size(split))
	{
		if (!flag && cmp_rank(split[idx], time, deathcount))
			flag = write_record(fd, name, str[0], str[1]);
		write(fd, split[idx], sl_strlen(split[idx]));
		write(fd, "\n", 1);
	}
	if (!flag)
		flag = write_record(fd, name, str[0], str[1]);
	free(str[0]);
	free(str[1]);
	sl_free_split(split);
	close(fd);
}
