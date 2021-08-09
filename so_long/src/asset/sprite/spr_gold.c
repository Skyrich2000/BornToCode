#include "engine.h"

int			init_spr_gold()
{
	g()->asset.spr_gold_red = add_sprite(16, 32, 10, (t_box){ 8, 8, 24, 24 });
	g()->asset.spr_gold_blue = add_sprite(16, 32, 10, (t_box){ 8, 8, 24, 24 });
	g()->asset.spr_gold_red_break = add_sprite(16, 32, 10, (t_box){ 8, 8, 24, 24 });
	if (!add_sprite_subimage(g()->asset.spr_gold_red, "./res/png/gold_red/gold_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_gold_blue, "./res/png/gold_blue/gold_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_gold_red_break, "./res/png/gold_red/gold_", 1, 4))
		return (ERROR);
	return (OK);
}
