#include "library.h"

void	sl_exit(int errno)
{
	printf("%s\n", strerror(errno));
	exit(errno);
}
