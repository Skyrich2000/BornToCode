#include "engine.h"

int			init_spr_gold()
{
	g()->asset.spr_gold = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	if (!g()->asset.spr_gold)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_gold, "./res/xpm/gold/gold_", 0, 0))
		return (ERROR);
	return (OK);
}
