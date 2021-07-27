#include "engine.h"

int			init_spr_logo()
{
	g()->asset.spr_logo = add_sprite(500 / 2, 116 / 2, 10, (t_box){ 0, 0, 0, 0 });
	if (!g()->asset.spr_logo)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_logo, "./res/png/logo/logo_", 3, 3))
		return (ERROR);
	return (OK);
}
