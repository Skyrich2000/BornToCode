#include "engine.h"

int init_spr_exit()
{
	g()->asset.spr_exit = add_sprite(16, 32, 10, (t_box){ 14, 14, 18, 18 });
	if (!g()->asset.spr_exit)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_exit, "./res/png/exit/exit_", 0, 0))
		return (ERROR);
	return (OK);
}
