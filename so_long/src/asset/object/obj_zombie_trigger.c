#include "engine.h"

t_instance *create_zombie_trigger_instance(int x, int y, t_instance *zombie)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_empty, (int[3]){ZOMBIE_TRIGGER, x, y}, obj_zombie_trigger_step, 0);
	if (!ins)
		return (ERROR);
	ins->obj.zombie_trigger.player = 0;
	ins->obj.zombie_trigger.zombie = zombie;
	return (ins);
}

void		obj_zombie_trigger_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_zombie_trigger_step start\n");
	if (g()->global.status == 1 &&
		this->obj.zombie_trigger.player && \
		place_meeting(this, this->x, this->y, this->obj.zombie_trigger.player))
	{
		printf("trigger!!!!\n");
		if (this->obj.zombie_trigger.zombie->obj.zombie.die == -1)
			this->obj.zombie_trigger.zombie->obj.zombie.die = 0;
		destroy_instance(this);
	}
	if (DEBUG)
		printf("obj_zombie_trigger_step end\n");
}
