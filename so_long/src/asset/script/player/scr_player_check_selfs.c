#include "engine.h"

void	scr_player_check_selfs(t_instance *this)
{
	t_list		*node;
	t_instance	*ins;

	node = g()->instances[PLAYER]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins == this)
			continue ;
		if (point_distance(ins->x, ins->y, this->x, this->y) < 32 * 32)
			scr_player_die(T_MEET_MYSELF);
	}
}
