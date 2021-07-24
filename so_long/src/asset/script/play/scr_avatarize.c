#include "engine.h"

void	scr_avatarize(int type)
{
	t_instance	*ins;
	t_list		*node;
	t_list		**route_node;

	node = g()->instances[type]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins->condition & C_AVATAR)
			continue ;
		ins->condition |= C_AVATAR;
		route_node = scr_get_route_node(ins, type);
		*route_node = scr_get_route(ins, type)->next;
	}
}