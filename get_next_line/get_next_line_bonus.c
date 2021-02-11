/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:36:55 by ycha              #+#    #+#             */
/*   Updated: 2021/02/11 11:59:59 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line_bonus.h"

/*
** size > 0 : ptr is valid
** size == 0 : ptr is end
** size == -1 : error
*/


void    print_hex(unsigned char c)
{
        write(1, "\\", 1);
        write(1, &"0123456789abcdef"[c / 16], 1);
        write(1, &"0123456789abcdef"[c % 16], 1);
}

int             is_printable(unsigned char c)
{
        return (32 <= c && c <= 126);
}

void    ft_putstr(char *str)
{
        int     len;

        len = 0;
        while (str[len])
                len++;
        write(1, str, len);
}

void    ft_putstr_non_printable(char *str)
{
        if (!str) {
                ft_putstr("(NULL)");
                return ;
        }
        while (*str)
        {
                if (is_printable(*str))
                        write(1, str, 1);
                else
                        print_hex(*str);
                str++;
        }
}

char    *set_ptr(char **out, char *str) {
        free(*out);
        if (*str == 0)
        {
                free(str);
                *out = 0;
        }
        else
                *out = str;
        return(*out);
}

int     get_next_line(int fd, char **line)
{
        int size;
        char *ptr;
        char buf[BUFFER_SIZE + 1];
        static char *save[FOPEN_MAX];

        size = 1;
        //ft_putstr("[@@@@@@@]before\n");
        //ft_putstr("[@@@@@@@]SAVE {");
        //ft_putstr_non_printable(save[fd]);
        //ft_putstr("}\n");
        while((ptr = ft_strchr(save[fd], '\n')) == 0) {
                if ((size = read(fd, buf, BUFFER_SIZE)) < 1)
                        break;
                //ft_putstr("[@@@@@@]read new from file\n");
                set_ptr(&save[fd], ft_strnjoin(save[fd], buf, size));
                //ft_putstr("[@@@@@@]SAVE {");
                //ft_putstr_non_printable(save[fd]);
                //ft_putstr("}\n");
        }
		if (line == 0 || size == -1 || BUFFER_SIZE < 1)
			return (-1);
        if (size == 0)
                ptr = ft_strchr(save[fd], 0);
        //ft_putstr("[@@@@]copy to line\n");
		*line = ft_strnjoin(0, save[fd], ptr - save[fd]);
        //ft_putstr("[@@@@]LINE {");
        //ft_putstr_non_printable(*line);
        //ft_putstr("}\n");
        //ft_putstr("[@@]update save from prev newline\n");
        set_ptr(&save[fd], ft_strnjoin(0, ptr ? ptr + 1 : 0, ft_strlen(save[fd]) - (ptr - save[fd])));
        //ft_putstr("[@@]SAVE {");
        //ft_putstr_non_printable(save[fd]);
        //ft_putstr("}\n");
        return (size < 1 ? size : 1);

}

int main(void)
{
	char *line = 0;
	int ret;
	int fd;

	fd = open("testfile2", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("                     [out%d]%s\n", ret, line);
		free(line);
	}
	printf("                       [out%d]%s\n", ret, line);
	free(line);
	return (0);
}

