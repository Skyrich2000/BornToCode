#include "engine.h"

t_instance *create_exit_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_exit, (int [3]){EXIT, x, y}, 0, draw_self);
	return (ins);
}