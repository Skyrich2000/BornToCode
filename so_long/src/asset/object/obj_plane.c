#include "engine.h"

t_instance *create_plane_instance()
{
	int			x;
	int			y;
	t_instance	*ins;

	x = g()->global.player->x;
	y = 500;
	ins = create_instance(g()->asset.spr_plane, (int [3]){PLANE, x, y}, obj_plane_step, obj_plane_draw);
	return (ins);
}

void		obj_plane_step(t_instance *this)
{
	if (DEBUG)
		printf("obj_plane_step start\n");

	if (g()->global.player && g()->global.player->y - 10 > this->y)
	{
		if (g()->global.invert_signal == SIG_NO_INVERT)
			g()->global.state = S_CLEAR;
		destroy_instance(g()->global.player);
		g()->global.player = 0;
	}
	this->y -= 5;
	if (this->y < g()->view.view_yview - 42)
	{
		destroy_instance(this);
	}

	if (DEBUG)
		printf("obj_plane_step end\n");
}

void		obj_plane_draw(t_instance *this)
{
	if (DEBUG)
		printf("obj_plane_draw start\n");
	draw_sprite(this->spr, this->spr->imgs->next, this->x, this->y);
	if (DEBUG)
		printf("obj_plane_draw start\n");
}
