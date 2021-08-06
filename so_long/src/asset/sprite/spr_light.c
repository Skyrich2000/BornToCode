#include "engine.h"

int			init_spr_light()
{
	g()->asset.spr_light = add_sprite(500, 500, 10, (t_box){ 0, 0, 0, 0 });
	g()->asset.spr_light_5 = add_sprite(500, 500, 10, (t_box){ 0, 0, 0, 0 });
	if (!add_sprite_subimage(g()->asset.spr_light, "./res/png/light/light_", 3, 3) || \
		!add_sprite_subimage(g()->asset.spr_light_5, "./res/png/light/light_", 2, 2))
		return (ERROR);
	return (OK);
}
