#include "engine.h"

int init_spr_exit()
{
	g()->asset.spr_exit = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	if (!g()->asset.spr_exit)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_exit, "./res/xpm/empty_", 0, 0))
		return (ERROR);
	return (OK);
}
