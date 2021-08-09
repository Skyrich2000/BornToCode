#include "library.h"

int sl_atoi(const char *str)
{
	int sign;
	long long result;

	sign = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		if (result < 0)
			return ((sign == 1) ? -1 : 0);
		str++;
	}
	return (result * sign);
}

int sl_abs(int a)
{
	return (a * ((a > 0) * 2 - 1));
}