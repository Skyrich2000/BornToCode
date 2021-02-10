#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
        char *line = 0;
        int ret;
        int fd;

        int flag;
        char temp[BUFFER_SIZE];
		for(flag = 0; flag < BUFFER_SIZE; flag++)
			temp[flag] = 'z';
        fd = open("testfile2", O_RDONLY);
        flag = read(fd, temp, BUFFER_SIZE);
        printf("flag : %d\n", flag);
        printf("%s", temp);
        flag = read(fd, temp, BUFFER_SIZE);
        printf("flag : %d\n", flag);
        printf("%s", temp);
        //while ((ret = get_next_line(fd, &line)) > 0)
        //{
//              printf("%s\n", line);
//              free(line);
//      }
        //free(line);
        return (0);
}

