/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 08:48:28 by ycha              #+#    #+#             */
/*   Updated: 2021/06/28 01:05:39 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*malloc_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (ERROR);
	node->data = data;
	node->link[next] = NULL;
	node->link[prev] = NULL;
	return (node);
}

void			init_list(int pos)
{
	t_list	*list;

	list = st();
	list->size[pos >> 1] = 0;
	list->n[pos >> 1][head] = malloc_node(next);
	list->n[pos >> 1][tail] = malloc_node(prev);
	list->n[pos >> 1][head]->link[next] = list->n[pos >> 1][tail];
	list->n[pos >> 1][tail]->link[prev] = list->n[pos >> 1][head];
}

int				swap(int pos)
{
	int		tmp;
	t_node	*node;

	if (st()->size[pos >> 1] < 2)
		return (ERROR);
	node = st()->n[pos >> 1][head]->link[next];
	tmp = node->data;
	node->data = node->link[next]->data;
	node->link[next]->data = tmp;
	return (OK);
}

int				push(int pos, int data)
{
	int		dir;
	t_node	*node;
	t_node	*new_node;

	node = st()->n[pos >> 1][pos & 1];
	dir = node->data;
	new_node = malloc_node(data);
	if (!new_node)
		return (ERROR);
	new_node->link[dir] = node->link[dir];
	new_node->link[!dir] = node;
	node->link[dir] = new_node;
	new_node->link[dir]->link[!dir] = new_node;
	st()->size[pos >> 1]++;
	return (OK);
}

int				pop(int pos, int *data)
{
	int		dir;
	t_node	*node;
	t_node	*del_node;

	node = st()->n[pos >> 1][pos & 1];
	if (!st()->size[pos >> 1])
		return (ERROR);
	dir = node->data;
	del_node = node->link[dir];
	*data = del_node->data;
	node->link[dir] = del_node->link[dir];
	del_node->link[dir]->link[!dir] = node;
	free(del_node);
	st()->size[pos >> 1]--;
	return (OK);
}
