#include "engine.h"

t_instance *create_wait_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_empty, (int [3]){WAIT, x, y}, 0, 0);
	return (ins);
}