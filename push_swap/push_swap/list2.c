/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:12:06 by ycha              #+#    #+#             */
/*   Updated: 2021/06/28 01:05:50 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*st(void)
{
	static t_list	_list;

	return (&_list);
}

static int	print_cmd(t_cmd cmd)
{
	char	*s;

	s = (char [12][4]){"sa", "sb", "ss", "pa", "pb", "pp", \
						"ra", "rb", "rr", "rra", "rrb", "rrr"}[cmd];
	while (*s)
		write(1, s++, 1);
	write(1, "\n", 1);
	return (OK);
}

static int	check_pair(t_node *node, t_cmd cmd1, t_cmd cmd2)
{
	return ((node->data == cmd1 && node->link[PREV]->data == cmd2) || \
			(node->data == cmd2 && node->link[PREV]->data == cmd1));
}

void	print_result(void)
{
	t_node	*node;
	int		flag;

	node = st()->n[PRINT][TAIL]->link[PREV];
	if (node->link[PREV])
	{
		while (node->link[PREV]->link[PREV])
		{
			flag = 0;
			if (check_pair(node, SA, SB))
				flag += print_cmd(SS);
			else if (check_pair(node, PA, PB))
				flag += OK;
			else if (check_pair(node, RA, RB))
				flag += print_cmd(RR);
			else if (check_pair(node, RRA, RRB))
				flag += print_cmd(RRR);
			else
				print_cmd(node->data);
			if (flag)
				node = node->link[PREV];
			node = node->link[PREV];
		}
		print_cmd(node->data);
	}
}

void	free_list(t_node *node)
{
	if (node->link[NEXT])
		free_list(node->link[NEXT]);
	free(node);
}
