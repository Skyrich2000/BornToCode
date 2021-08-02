#include "engine.h"

int			init_spr_gold()
{
	g()->asset.spr_gold = add_sprite(16, 32, 10, (t_box){ 8, 8, 24, 24 });
	g()->asset.spr_gold_break = add_sprite(16, 32, 10, (t_box){ 8, 8, 24, 24 });
	if (!add_sprite_subimage(g()->asset.spr_gold, "./res/png/gold/gold_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_gold_break, "./res/png/gold/gold_", 1, 4))
		return (ERROR);
	return (OK);
}
