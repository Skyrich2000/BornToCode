#include "engine.h"

t_instance *create_plane_instance()
{
	int			x;
	int			y;
	t_instance	*ins;

	x = g()->global.player->x;
	y = 500;
	ins = create_instance(g()->asset.spr_plane, (int [3]){PLANE, x, y}, obj_plane_step, obj_plane_draw);
	if (!ins)
		return (ERROR);
	return (ins);
}

void		obj_plane_step(t_instance *this)
{
	if (g()->global.player && point_distance(g()->global.player->x, g()->global.player->y, this->x, this->y) < 15 * 15)
	{
		// g()->global.player->spr = g()->asset.spr_empty;
		destroy_instance(g()->global.player);
		g()->global.player = 0;
	}
	this->y -= 5;
	if (this->y < -42)
		destroy_instance(this);
}

void		obj_plane_draw(t_instance *this)
{
	draw_sprite(this->spr, this->spr->imgs->next, this->x, this->y);
}
