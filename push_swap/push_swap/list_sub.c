/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:12:06 by ycha              #+#    #+#             */
/*   Updated: 2021/06/24 14:12:07 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	_print_list(char *prefix, int pos)
{
	t_node *node;

	printf("%s", prefix);
	node = st()->n[pos >> 1][pos & 1]->link[next];
	while (node->link[next])
	{
		printf("%d ", node->data);
		node = node->link[next];
	}
	printf("\n");
}

void	print_list(char *prefix)
{
	printf("%s\n", prefix);
	_print_list("a : ", (A << 1)|head);
	_print_list("b : ", (B << 1)|head);
}

void	free_list(t_node *node)
{
	if (node->link[next])
		free_list(node->link[next]);
	free(node);
}
