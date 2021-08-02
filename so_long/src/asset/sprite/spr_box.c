#include "engine.h"

int			init_spr_box()
{
	g()->asset.spr_box = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	g()->asset.spr_box_break = add_sprite(16, 32, 6, (t_box){ 0, 0, 32, 32 });
	if (!add_sprite_subimage(g()->asset.spr_box, "./res/png/box/box_", 0, 0) ||
		!add_sprite_subimage(g()->asset.spr_box_break, "./res/png/box/box_", 1, 4))
		return (ERROR);
	return (OK);
}
