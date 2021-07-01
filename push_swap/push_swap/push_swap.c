/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:07:14 by ycha              #+#    #+#             */
/*   Updated: 2021/06/28 01:05:59 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	is_unique(int num)
{
	t_node	*node;

	node = st()->n[A][HEAD]->link[NEXT];
	while (node->link[NEXT])
	{
		if (node->data == num)
			return (ERROR);
		node = node->link[NEXT];
	}
	return (OK);
}

static int	is_num(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (ERROR);
		str++;
	}
	return (OK);
}

static int	_input(char *str)
{
	int		j;
	int		data;
	char	**sp;
	char	**s;

	sp = ft_split(str, ' ');
	j = 0;
	s = sp;
	while (s && *s++)
		j++;
	if (j == 0)
		return (ERROR);
	while (j--)
	{
		if (!(is_num(sp[j]) && ft_atoi(sp[j], &data) && is_unique(data)))
			return (ERROR);
		push(A | HEAD, data);
	}
	s = sp;
	while (*s)
		free(*s++);
	free(sp);
	return (OK);
}

static int	input(int ac, char **av)
{
	int	i;

	init_list(A);
	init_list(B);
	init_list(PRINT);
	i = ac;
	while (--i > 0)
		if (!_input(av[i]))
			return (ERROR);
	return (OK);
}

int	main(int ac, char **av)
{
	if (!input(ac, av))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (st()->size[A] == 3)
		sort_three();
	else if (st()->size[A] == 5)
		sort_five();
	else
		A_to_B(st()->size[A]);
	print_result();
	free_list(st()->n[A][HEAD]);
	free_list(st()->n[B][HEAD]);
	free_list(st()->n[PRINT][HEAD]);
	return (0);
}
