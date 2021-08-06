#include "engine.h"

t_instance *create_box_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_box, (int[3]){BOX, x, y}, obj_box_step, obj_box_draw);
	ins->obj.box.route = create_list();
	ins->obj.box.route_node = 0;
	ins->condition = C_ALIVE;
	return (ins);
}

void		obj_box_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_box_step start\n");

	if (!(this->condition & C_AVATAR))
	{
		if (this->condition & C_DEING)
		{
			change_sprite(this, g()->asset.spr_box_break);
			if (this->img_node->next == 0)
				this->condition = C_DEAD;
		}
		else if (this->condition & C_DEAD)
			change_sprite(this, g()->asset.spr_empty);
		if (g()->global.state == S_STRAIGHT)
			scr_save_footprint(this, this->obj.box.route);
	}
	else if (g()->global.state != S_GAMEOVER)
	{
		if (g()->global.time > 0)
			scr_load_footprint(this, &this->obj.box.route, 0);
	}

	if (DEBUG)
		printf("obj_box_step end\n");
}

void		obj_box_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_box_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);
	if (!(this->condition & C_AVATAR))
		scr_animation(this);

	if (DEBUG)
		printf("obj_box_draw end\n");
}
