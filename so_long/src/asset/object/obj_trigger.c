#include "engine.h"

t_instance *create_trigger_instance(int pos[2], t_sprite *mask, t_instance *target, int signal)
{
	t_instance *ins;

	ins = create_instance(mask, (int[3]){TRIGGER, pos[0], pos[1]}, 0, 0);
	if (!ins)
		return (ERROR);
	ins->obj.trigger.target = target;
	ins->obj.trigger.signal = signal;
	return (ins);
}
