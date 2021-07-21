#include "engine.h"

t_instance *create_box_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_box, (int[3]){BOX, x, y}, obj_box_step, obj_box_draw);
	if (!ins)
		return (ERROR);
	ins->obj.box.avatar = 0;
	ins->obj.box.status = 0;
	ins->obj.box.route = create_list();
	ins->obj.box.route_node = 0;
	return (ins);
}

/*
** 0 : normal
** 1 : break animation
** 2 : break
*/
void		obj_box_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_box_step start\n");

	if (this->obj.box.avatar == 0)
	{
		if (this->obj.box.status == 1) // break animation
		{
			change_sprite(this, g()->asset.spr_box_break);
			if (this->img_node->next == 0) // if break animation done
				this->obj.box.status = 2;
		}
		else if (this->obj.box.status == 2) // break
			change_sprite(this, g()->asset.spr_empty);
		b_footprint(this);
	}

	if (DEBUG)
		printf("obj_box_step end\n");
}


void		obj_box_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_box_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);

	if (this->obj.box.avatar == 0)
		scr_animation(this);

	if (DEBUG)
		printf("obj_box_draw end\n");
}
