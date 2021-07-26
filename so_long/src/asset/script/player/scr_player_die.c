#include "engine.h"

void	scr_player_die()
{
	t_instance	*ins;
	t_list		*node;

	if (g()->global.state != S_GAMEOVER)
	{
		printf("GAME OVER!!!\n");
		g()->global.deathcount++;
		g()->global.delay = 0;
		g()->global.state = S_GAMEOVER;
		node = g()->instances[PLAYER]->next;
		while (node)
		{
			ins = node->data;
			ins->signal = 0;
			ins->condition = C_DEING;
			node = node->next;
		}
	}
}
