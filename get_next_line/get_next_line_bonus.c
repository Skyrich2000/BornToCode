/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:36:55 by ycha              #+#    #+#             */
/*   Updated: 2021/02/12 15:00:21 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*set_ptr(char **out, char *str)
{
	free(*out);
	if (*str == 0)
	{
		free(str);
		*out = 0;
	}
	else
		*out = str;
	return (*out);
}

int		get_next_line(int fd, char **line)
{
	int			flag;
	char		*ptr;
	char		buf[BUFFER_SIZE + 1];
	static char *save[OPEN_MAX];

	flag = 1;
	if (read(fd, buf, 0) == -1 || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((ptr = ft_strchr(save[fd], '\n')) == 0)
	{
		if ((flag = read(fd, buf, BUFFER_SIZE)) < 1)
			break ;
		set_ptr(&save[fd], ft_strnjoin(save[fd], buf, flag));
	}
	ptr = flag ? ptr : ft_strchr(save[fd], 0);
	*line = ft_strnjoin(0, save[fd], ptr - save[fd]);
	set_ptr(&save[fd], ft_strnjoin(0, flag ? ptr + 1 : 0,
							ft_strlen(save[fd]) - (ptr - save[fd])));
	return (flag > 0 ? 1 : flag);
}
