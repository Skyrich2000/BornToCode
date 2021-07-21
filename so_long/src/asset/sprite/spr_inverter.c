#include "engine.h"

int init_spr_inverter()
{
	g()->asset.spr_inverter_blue = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	g()->asset.spr_inverter_red = add_sprite(16, 32, 10, (t_box){ 0, 0, 32, 32 });
	if (!g()->asset.spr_inverter_blue || \
		!g()->asset.spr_inverter_red)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_inverter_blue, "./res/xpm/inverter/inverter_blue_", 0, 3) || \
		!add_sprite_subimage(g()->asset.spr_inverter_red, "./res/xpm/inverter/inverter_red_", 0, 3))
		return (ERROR);
	return (OK);
}
