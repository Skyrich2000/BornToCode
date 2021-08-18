/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:12 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:28:26 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"
#include "engine/engine_list_bonus.h"

t_list	*create_list(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		sl_exit(12);
	new->data = 0;
	new->prev = 0;
	new->next = 0;
	return (new);
}

t_list	*push_list(t_list *list, void *data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		sl_exit(12);
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
	void	*data;

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
	if (del && list->data)
		del(list->data);
	free(list);
}
