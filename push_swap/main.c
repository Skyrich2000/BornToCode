/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:07:14 by ycha              #+#    #+#             */
/*   Updated: 2021/06/21 17:43:18 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_list	*st()
{
	static t_list _list;

	return (&_list);
}

//debug
static int		printf_(char *str)
{
	//return 1;
	return (printf("%s", str));
}

void	c(t_cmd cmd)
{
	int tmp;

	(cmd == sa) && printf_("sa\n") && swap(A);
	(cmd == sb) && printf_("sb\n") && swap(B);
	(cmd == ss) && printf_("ss\n") && swap(A) && swap(B);
	(cmd == pa) && printf_("pa\n") && pop(B|head, &tmp) && push(A|head, tmp);
	(cmd == pb) && printf_("pb\n") && pop(A|head, &tmp) && push(B|head, tmp);
	(cmd == ra) && printf_("ra\n") && pop(A|head, &tmp) && push(A|tail, tmp);
	(cmd == rb) && printf_("rb\n") && pop(B|head, &tmp) && push(B|tail, tmp);
	(cmd == rr) && printf_("rr\n") && pop(A|head, &tmp) && push(A|tail, tmp) \
								&& pop(B|head, &tmp) && push(B|tail, tmp);
	(cmd == rra) && printf_("rra\n") && pop(A|tail, &tmp) && push(A|head, tmp);
	(cmd == rrb) && printf_("rrb\n") && pop(B|tail, &tmp) && push(B|head, tmp);
	(cmd == rrr) && printf_("rrr\n") && pop(A|tail, &tmp) && push(A|head, tmp) \
								  && pop(B|tail, &tmp) && push(B|head, tmp);
}

static int	ft_atoi(char *str)
{
		int				sign;
		long long		result;

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

static void	init(int ac, char **av)
{
	int i;

	init_list(A);
	init_list(B);
	i = ac - 1;
	while (i > 0)
		push(A|head, ft_atoi(av[i--]));
}

int main(int ac, char **av)
{
	init(ac, av);
	sort();
	free_list(st()->n[A >> 1][head]);
	free_list(st()->n[B >> 1][head]);
	return 0;
}
