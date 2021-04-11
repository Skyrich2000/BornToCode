#include "library.h"

double	rand_num(int anti, int min, int max)
{
	if (anti == 0)
		return (0);
	if (min < max)
		return ((double)(min + (max - min)) *rand_num(1, 0, 0));
	else
		return ((double)rand() / (double)RAND_MAX);
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

double	clamp(double n, double min, double max)
{
	if (n < min)
		return (min);
	if (n > max)
		return (max);
	return (n);
}

double ft_abs(double n)
{
	if (0 > n)
		return (-n);
	return (n);
}

double ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
