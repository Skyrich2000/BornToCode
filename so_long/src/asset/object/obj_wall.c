#include "engine.h"

t_instance *create_wall_instance(int x, int y)
{
	t_instance *ins;

	ins = create_instance(g()->asset.spr_wall, (int[3]){WALL, x, y}, 0, obj_wall_draw);
	if (!ins)
		return (ERROR);
	return (ins);
}

void		obj_wall_draw(t_instance *this)
{
	draw_sprite(this->spr, this->spr->imgs->next, this->x, this->y);
}
