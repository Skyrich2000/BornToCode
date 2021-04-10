#include "library.h"

double	rand_num(int anti, int min, int max)
{
	if (anti == 0)
		return (0);
	if (min < max)
		return ((double)(min + (max - min)) * rand_num(1, 0, 0));
	else
		return ((double)rand() / (double)RAND_MAX);
}
