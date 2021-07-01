#include "push_swap.h"

int	ft_atoi(char *str, int *data)
{
	int			sign;
	long long	result;

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
		str++;
	}
	result *= sign;
	if (result < -2147483648 || result > 2147483647)
		return (ERROR);
	*data = result;
	return (OK);
}

void	ft_bzero(void *s, int n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n--)
	{
		*ptr = 0;
		ptr++;
	}
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
