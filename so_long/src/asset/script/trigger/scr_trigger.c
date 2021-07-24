#include "engine.h"

void		scr_trigger(t_instance *trigger, t_instance *player)
{
	if (player->obj.inverter.inverted == trigger->obj.trigger.inverted)
	{
		trigger->obj.trigger.target->signal = trigger->obj.trigger.signal;
		destroy_instance(trigger);
	}
}
