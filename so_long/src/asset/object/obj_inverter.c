#include "engine.h"

// out_dir[SIG_MV_LEFR] = SIG_MV_DOWN
// out_dir[SIG_MV_DOWN] = SIG_MV_LEFT
t_instance *create_inverter_instance(int x, int y, int inverted, int out_dir[20])
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_inverter_idle, (int[3]){INVERTER, x, y}, obj_inverter_step, obj_inverter_draw);
	if (!ins)
		return (ERROR);
	ins->obj.inverter.time = 60;
	ins->obj.inverter.inverted = inverted;
	ins->obj.inverter.out_dir[SIG_MV_LEFT] = out_dir[SIG_MV_LEFT];
	ins->obj.inverter.out_dir[SIG_MV_RIGHT] = out_dir[SIG_MV_RIGHT];
	ins->obj.inverter.out_dir[SIG_MV_UP] = out_dir[SIG_MV_UP];
	ins->obj.inverter.out_dir[SIG_MV_DOWN] = out_dir[SIG_MV_DOWN];
	ins->condition = C_ALIVE;
	scr_inverter_create_trigger(ins);
	return (ins);
}

void		obj_inverter_step(t_instance *this)
{
	t_sprite	*spr;

	if (DEBUG)
		printf("obj_inverter_step start\n");

	if (g()->global.inverted == this->obj.inverter.inverted)
	{
		spr = g()->asset.spr_inverter_red;
		if (this->obj.inverter.inverted)
			spr = g()->asset.spr_inverter_blue;
		change_sprite(this, spr);
	}
	else
		change_sprite(this, g()->asset.spr_inverter_idle);

	if (this->signal & SIG_BEFORE)
	{
		if (this->obj.inverter.inverted == S_INVERT && g()->global.time > this->obj.inverter.time)
		{
			if (!(g()->global.player->signal & SIG_AUTO))
				scr_inverter_wait(this);
		}
		else
		{
			scr_inverter_before(this);
			this->signal = 0;
		}
	}
	else if (this->signal & SIG_ACTIVE)
	{
		scr_inverter_active(this);
		this->signal = 0;
	}

	if (DEBUG)
		printf("obj_inverter_step end\n");
}

void		obj_inverter_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_inverter_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);
	scr_animation(this);

	if (DEBUG)
		printf("obj_inverter_draw end\n");
}
