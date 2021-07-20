#include "engine.h"

t_instance *create_box_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_box, (int[3]){BOX, x, y}, obj_box_step, obj_box_draw);
	if (!ins)
		return (ERROR);
	ins->obj.box.status = 0;
	ins->obj.box.route = create_list();
	return (ins);
}

static void b_footprint(t_instance *this)
{
	t_footprint	*footprint;

	footprint = malloc(sizeof(t_footprint));
	footprint->x = this->x;
	footprint->y = this->y;
	footprint->spr = this->spr;
	footprint->img_node = this->img_node;
	push_list(this->obj.box.route, footprint);
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
	if (this->obj.box.status == 1)
	{
		change_sprite(this, g()->asset.spr_box_break);
		if (this->img_node->next == 0)
			this->obj.box.status = 2;
	}
	else if (this->obj.box.status == 2) // break
	{
		change_sprite(this, g()->asset.spr_empty);
	}
	if (g()->global.status == 0)
		b_footprint(this);
	if (DEBUG)
		printf("obj_box_step end\n");
}


void		obj_box_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_box_draw start\n");
	draw_sprite(this->spr, this->img_node, this->x, this->y);
	this->draw_time++;
	if (this->draw_time > this->spr->img_speed)
	{
		this->img_node = this->img_node->next;
		this->draw_time = 0;
	}
	if (!this->img_node)
		this->img_node = this->spr->imgs->next;
	if (DEBUG)
		printf("obj_box_draw end\n");
}
