#include "engine.h"

t_instance *create_trigger_instance(int pos[2], int inverted, t_instance *target, int signal)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_empty, (int[3]){TRIGGER, pos[0], pos[1]}, 0, 0);
	ins->obj.trigger.target = target;
	ins->obj.trigger.signal = signal;
	ins->obj.trigger.inverted = inverted;
	return (ins);
}
