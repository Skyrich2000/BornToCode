/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 08:48:28 by ycha              #+#    #+#             */
/*   Updated: 2021/07/02 00:02:20 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define MASK 0b110

static t_node	*malloc_node(int data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (ERROR);
	node->data = data;
	node->link[NEXT] = NULL;
	node->link[PREV] = NULL;
	return (node);
}

void	init_list(int pos)
{
	t_list	*list;

	list = st();
	list->size[pos & MASK] = 0;
	list->n[pos & MASK][HEAD] = malloc_node(NEXT);
	list->n[pos & MASK][TAIL] = malloc_node(PREV);
	list->n[pos & MASK][HEAD]->link[NEXT] = list->n[pos & MASK][TAIL];
	list->n[pos & MASK][TAIL]->link[PREV] = list->n[pos & MASK][HEAD];
}

int	swap(int pos)
{
	int		tmp;
	t_node	*node;

	if (st()->size[pos & MASK] < 2)
		return (ERROR);
	node = st()->n[pos][HEAD]->link[NEXT];
	tmp = node->data;
	node->data = node->link[NEXT]->data;
	node->link[NEXT]->data = tmp;
	return (OK);
}

int	push(int pos, int data)
{
	int		dir;
	t_node	*node;
	t_node	*new_node;

	node = st()->n[pos & MASK][pos & 1];
	dir = node->data;
	new_node = malloc_node(data);
	if (!new_node)
		return (ERROR);
	new_node->link[dir] = node->link[dir];
	new_node->link[!dir] = node;
	node->link[dir] = new_node;
	new_node->link[dir]->link[!dir] = new_node;
	st()->size[pos & MASK]++;
	return (OK);
}

int	pop(int pos, int *data)
{
	int		dir;
	t_node	*node;
	t_node	*del_node;

	node = st()->n[pos & MASK][pos & 1];
	if (!st()->size[pos & MASK])
		return (ERROR);
	dir = node->data;
	del_node = node->link[dir];
	*data = del_node->data;
	node->link[dir] = del_node->link[dir];
	del_node->link[dir]->link[!dir] = node;
	free(del_node);
	st()->size[pos & MASK]--;
	return (OK);
}
