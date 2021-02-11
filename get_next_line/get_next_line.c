/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:36:55 by ycha              #+#    #+#             */
/*   Updated: 2021/02/11 16:22:42 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <fcntl.h>
#include "get_next_line.h"

static int		ft_strncat(char *dest, char *src, int n, char **out, int need_free)
{
	int len;
	char *ret;

//	need_free = 1;
	len = ft_strlen(dest) + n + 1;
//	printf("%s:%s:%d=", dest, src, len); 
	if (len == 0 || (ret = malloc(len)) == 0) {
		if (need_free) {
			free(*out);
			*out = 0;
		}
		return (0);
	}
	*ret = 0;
	if (dest)
		ft_strlcat(ret, dest, len);
	ft_strlcat(ret, src, len);
	if (need_free)
		free(*out);
	*out = ret;
//	printf("%s;\n", *out);
	return (1);
}

/*
** size > 0 : ptr is valid
** size == 0 : ptr is end
** size == -1 : error
*/

int     get_next_line(int fd, char **line)
{
	int size;
	char *ptr;
	char temp[BUFFER_SIZE];
	static char *buf;

	size = 1;
	while((ptr = ft_strchr(buf, '\n')) == 0) {
		if ((size = read(fd, temp, BUFFER_SIZE)) < 1)
			break;
//		printf("[@@@@@@@DEBUG]read new from file\n");
		ft_strncat(buf, temp, size, &buf, buf ? 1 : 0);
	}
	if (size == -1)
		return (size);
	if (size == 0)
		ptr = ft_strchr(buf, 0);
//	printf("[@@@@@@@DEBUG]buf : %p\n", buf);
//	printf("[@@@@@@@DEBUG]ptr : %p\n", ptr);
//	printf("[@@@@@@@DEBUG]size : %d\n", size);
//	printf("[@@@@@@@DEBUG]copy to line\n");
	ft_strncat(0, buf, ptr - buf, line, 0);
//	printf("[@@@@@@@DEBUG]update buf from prev newline\n");
	ft_strncat(0, ptr + 1, ft_strlen(ptr) - 1, &buf, buf ? 1 : 0);
	return (size ? 1 : 0);
}
/*
int	main(void) {
	static char *buf;
	ft_strncat(0, "abcd", 4, &buf);
	printf("buf : %s\n", buf);
	return (0);
}
*/

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
