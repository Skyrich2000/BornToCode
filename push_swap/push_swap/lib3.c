/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 01:46:57 by ycha              #+#    #+#             */
/*   Updated: 2021/02/12 14:45:56 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define BUFFER_SIZE 10

static int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

static char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (0);
}

static char	*ft_strnjoin(char *s1, char *s2, int m)
{
	int		n;
	char	*ret;

	n = ft_strlen(s1);
	ret = (char *)malloc(n + m + 1);
	if (!ret)
		return (0);
	ft_bzero(ret, n + m + 1);
	if (s1)
		ft_memcpy(ret, s1, n);
	if (s2)
		ft_memcpy(ret + n, s2, m);
	ret[n + m] = 0;
	return (ret);
}

static int	set_ptr(char **out, char *str)
{
	free(*out);
	if (!str)
		return (0);
	if (*str == 0)
	{
		free(str);
		*out = 0;
	}
	else
		*out = str;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			flag;
	char		*ptr;
	char		buf[BUFFER_SIZE + 1];
	static char	*save;

	flag = 1;
	if (read(fd, buf, 0) == -1 || line == 0 || BUFFER_SIZE < 1)
		return (-1);
	ptr = ft_strchr(save, '\n');
	while (ptr == 0)
	{
		flag = read(fd, buf, BUFFER_SIZE);
		if (flag < 1)
			break ;
		if (!(set_ptr(&save, ft_strnjoin(save, buf, flag))))
			return (-1);
		ptr = ft_strchr(save, '\n');
	}
	if (!flag)
		ptr = ft_strchr(save, 0);
	*line = ft_strnjoin(0, save, ptr - save);
	if (!*line || !(set_ptr(&save, ft_strnjoin(0, ptr + (flag != 0), \
					ft_strlen(save) - (ptr - save)))))
		return (-1);
	return (flag);
}
