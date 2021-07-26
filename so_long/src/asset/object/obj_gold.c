#include "engine.h"

t_instance *create_gold_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_gold, (int[3]){GOLD, x, y}, obj_gold_step, obj_gold_draw);
	if (!ins)
		return (ERROR);
	ins->obj.gold.route = create_list();
	ins->obj.gold.route_node = 0;
	ins->condition = C_ALIVE;
	return (ins);
}

void		obj_gold_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_gold_step start\n");

	if (!(this->condition & C_AVATAR))
	{
		if (this->condition & C_DEING)
		{
			change_sprite(this, g()->asset.spr_gold_break);
			if (this->img_node->next == 0)
				this->condition = C_DEAD;
		}
		else if (this->condition & C_DEAD)
			change_sprite(this, g()->asset.spr_empty);
		if (g()->global.state == S_STRAIGHT || g()->global.state == S_READY)
			scr_save_footprint(this, this->obj.gold.route);
	}
	else if (g()->global.state != S_GAMEOVER)
		scr_load_footprint(this, &this->obj.gold.route, 0);

	if (DEBUG)
		printf("obj_gold_step end\n");
}

void		obj_gold_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_gold_draw start\n");

	draw_sprite(this->spr, this->img_node, this->x, this->y);
	if (!(this->condition & C_AVATAR))
		scr_animation(this);

	if (DEBUG)
		printf("obj_gold_draw end\n");
}
