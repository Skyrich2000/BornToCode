#include "engine.h"

t_instance *create_exit_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_exit, (int [3]){EXIT, x, y}, 0, obj_exit_draw);
	if (!ins)
		return (ERROR);
	return (ins);
}

void		obj_exit_draw(t_instance *this)
{
	draw_sprite(this->spr, this->spr->imgs->next, this->x, this->y);}
