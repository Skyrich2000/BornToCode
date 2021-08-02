#include "engine.h"

int init_spr_plane()
{
	g()->asset.spr_plane = add_sprite(32, 32, 10, (t_box){ 0, 0, 32, 32 });
	if (!add_sprite_subimage(g()->asset.spr_plane, "./res/png/plane/plane_", 3, 3))
		return (ERROR);
	return (OK);
}
