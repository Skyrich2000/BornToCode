/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:07:14 by ycha              #+#    #+#             */
/*   Updated: 2021/06/24 14:11:59 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

t_list	*st()
{
	static t_list _list;

	return (&_list);
}

static int	is_unique(int num)
{
	t_node *node;

	node = st()->n[A][head]->link[next];
	while (node->link[next])
	{
		if (node->data == num)
			return (ERROR);
		node = node->link[next];
	}
	return (OK);
}

static int	is_num(char *str)
{
	if (*str == '-')
		str++;
	while(*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (ERROR);
		str++;
	}
	return (OK);
}

static int	input(int ac, char **av)
{
	int i;
	int data;

	init_list(A << 1);
	init_list(B << 1);
	i = ac - 1;
	while (i > 0)
	{
		if (!(is_num(av[i]) && ft_atoi(av[i], &data) && is_unique(data)))
			return (ERROR);
		push(A|head, data);
		--i;
	}
	return (OK);
}

int main(int ac, char **av)
{
	if (!input(ac, av))
	{
		printf("Error\n");
		return (0);
	}
	if (st()->size[A] == 3)
		sort_three();
	else if (st()->size[A] == 5)
		sort_five();
	else
		A_to_B(st()->size[A]);
	//print_list("result");
	free_list(st()->n[A][head]);
	free_list(st()->n[B][head]);
	return (0);
}
