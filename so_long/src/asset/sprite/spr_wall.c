#include "engine.h"

int			init_spr_wall()
{
	g()->asset.spr_wall = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	if (!g()->asset.spr_wall)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_wall, "./res/xpm/wall/wall_", 0, 0))
		return (ERROR);
	return (OK);
}
