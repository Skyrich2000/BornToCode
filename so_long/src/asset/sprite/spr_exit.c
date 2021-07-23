#include "engine.h"

int init_spr_exit()
{
	g()->asset.spr_exit_open = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	g()->asset.spr_exit_close = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	if (!g()->asset.spr_exit_open || \
		!g()->asset.spr_exit_close)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_exit_open, "./res/png/exit/exit_", 1, 1) || \
		!add_sprite_subimage(g()->asset.spr_exit_close, "./res/png/exit/exit_", 0, 0))

		return (ERROR);
	return (OK);
}
