#include "engine.h"

int			init_spr_light()
{
	g()->asset.spr_light = add_sprite(500, 500, 10, (t_box){ 0, 0, 0, 0 });
	g()->asset.spr_light_dark = add_sprite(500, 500, 10, (t_box){ 0, 0, 0, 0 });
	if (!g()->asset.spr_light || \
		!g()->asset.spr_light_dark)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_light, "./res/png/light/light_", 3, 3) || \
		!add_sprite_subimage(g()->asset.spr_light_dark, "./res/png/light/light_", 4, 4))
		return (ERROR);
	return (OK);
}
