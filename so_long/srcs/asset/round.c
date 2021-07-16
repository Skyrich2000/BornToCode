#include "engine.h"

t_instance *create_round_instance()
{
	t_instance *ins;

	ins = create_instance(0, (int [3]){ROUND, 0, 0}, 0, 0);
	if (!ins)
		return (ERROR);
	ins->obj.round.straight = create_list();
	ins->obj.round.reverse = create_list();
	ins->obj.round.steps = 0;
	ins->obj.round.deathcount = 0;
	ins->obj.round.inverted = 0;
	return (ins);
}
