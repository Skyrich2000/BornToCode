#include "engine.h"

static int	sl_pow(int base, int exp)
{
	if (exp == 0)
		return (1);
	return (base * sl_pow(base, exp - 1));
}

int	sl_rev_atoi(char *str)
{
	int	n;
	int	idx;
	int	result;

	n = 0;
	result = 0;
	idx = sl_strlen(str) - 1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		result += (str[idx] - '0') * sl_pow(10, n);
		--idx;
		++n;
	}
	return (result);
}
