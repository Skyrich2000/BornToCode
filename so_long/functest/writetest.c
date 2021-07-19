#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	int fd;

	fd = open("./test.txt", O_WRONLY | O_CREAT, 0777);
	write(fd, "hello ", 6);
	write(fd, "world", 5);
	return (0);
}
