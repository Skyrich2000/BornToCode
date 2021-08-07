#include "engine.h"

// out_dir[SIG_MV_LEFR] = SIG_MV_DOWN
// out_dir[SIG_MV_DOWN] = SIG_MV_LEFT
t_instance *create_inverter_instance(int x, int y, int inverted, int out_dir[20])
{
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_inverter_idle, (int[3]){INVERTER, x, y}, obj_inverter_step, obj_inverter_draw);
	ins->obj.inverter.time = 0;
	ins->obj.inverter.inverted = inverted;
	ins->obj.inverter.dummy = 0;
	ins->obj.inverter.out_dir[SIG_MV_LEFT] = out_dir[SIG_MV_LEFT];
	ins->obj.inverter.out_dir[SIG_MV_RIGHT] = out_dir[SIG_MV_RIGHT];
	ins->obj.inverter.out_dir[SIG_MV_UP] = out_dir[SIG_MV_UP];
	ins->obj.inverter.out_dir[SIG_MV_DOWN] = out_dir[SIG_MV_DOWN];
	ins->condition = C_ALIVE;
	if (inverted == S_STRAIGHT)
		scr_inverter_create_trigger(ins);
	else
		scr_inverter_create_wait(ins);
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

	if (g()->global.state == S_GAMEOVER)
	{
		g()->frame.skip_frame = 0;
		g()->global.darkness = 0;
		return ;
	}

	if (g()->global.inverted == S_INVERT && g()->global.time == 0)
	{
		scr_inverter_destroy_wait(this);
		scr_inverter_create_trigger(this);
	}

	if (this->obj.inverter.inverted == g()->global.inverted)
	{
		if (this->signal & SIG_BEFORE)
			scr_inverter_before(this);
		else if (this->signal & SIG_ACTIVE)
			scr_inverter_active(this);
		this->signal = 0;
	}

	if (this->obj.inverter.dummy)
	{
		g()->frame.skip_frame = this->obj.inverter.time / 4;
		g()->global.darkness = this->obj.inverter.time / 3;
		this->obj.inverter.time++;
	}
	else if (this->obj.inverter.time)
	{
		g()->frame.skip_frame = this->obj.inverter.time / 4;
		g()->global.darkness = this->obj.inverter.time / 3;
		this->obj.inverter.time--;
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
