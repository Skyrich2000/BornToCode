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

int		push_list(t_list *list, void *data)
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
	return (OK);
}

void	free_list(t_list *list, void (*del)(void *))
{
	if (list->next)
		free_list(list->next, del);
	if (del)
		del(list->data);
	free(list);
}
