#include "engine.h"

void		scr_trigger(t_instance *trigger)
{
	trigger->obj.trigger.target->signal = trigger->obj.trigger.signal;
	destroy_instance(trigger);
}
