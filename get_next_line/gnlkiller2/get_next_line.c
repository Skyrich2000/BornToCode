/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:36:55 by ycha              #+#    #+#             */
/*   Updated: 2021/02/09 17:10:21 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     get_next_line(int fd, char **line)
{
	int len;
	int nr;
	static char buf[BUFFER_SIZE];
	char* ptr;

	len = BUFFER_SIZE;
	ptr = buf;
	while ((nr = read(fd, ptr, 1)) != 0)
	{
		if (nr == -1)
			return (-1);
		if (*ptr == '\n')
		{
			*ptr = '\0';
			*line = ft_strdup(buf);
			return (1);
		}
		if (!len--)
			return (-1);
		++ptr;
	}
	*ptr = '\0';
	*line = ft_strdup(buf);
	return (0);
}
/*
int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("testfile2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	return (0);
}
*/
