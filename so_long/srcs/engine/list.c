/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:12 by ycha              #+#    #+#             */
/*   Updated: 2021/07/16 07:49:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_list	*create_list()
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (ERROR);
	new->prev = 0;
	new->next = 0;
	return (new);
}

t_list	*push_list(t_list *list, void *data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (ERROR);
	new->data = data;
	new->prev = list;
	new->next = list->next;
	if (new->next)
		new->next->prev = new;
	new->prev->next = new;
	return (new);
}

void	*pop_list(t_list *node)
{
	void *data;

	data = node->data;
	node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	free(node);
	return (data);
}

void	free_list(t_list *list, void (*del)(void *))
{
	if (list->next)
		free_list(list->next, del);
	if (del)
		del(list->data);
	free(list);
}
