#include "engine.h"

void	scr_player_die(int text)
{
	t_instance	*ins;
	t_list		*node;

	if (g()->global.state != S_GAMEOVER)
	{
		g()->global.deathcount++;
		g()->global.delay = 0;
		g()->global.state = S_GAMEOVER;
		g()->global.text = text;
		node = g()->instances[PLAYER]->next;
		while (node)
		{
			ins = node->data;
			ins->signal = 0;
			ins->condition = C_DEING;
			node = node->next;
		}
		node = g()->instances[PLAYER]->next;
		while (g()->instances[DUMMY]->next)
			destroy_instance(g()->instances[DUMMY]->next->data);
	}
}
