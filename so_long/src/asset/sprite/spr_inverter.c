#include "engine.h"

int init_spr_inverter()
{
	g()->asset.spr_inverter_idle = add_sprite(16, 32, 10, (t_box){ 14, 14, 18, 18 });
	g()->asset.spr_inverter_blue = add_sprite(16, 32, 50, (t_box){ 14, 14, 18, 18 });
	g()->asset.spr_inverter_red = add_sprite(16, 32, 50, (t_box){ 14, 14, 18, 18 });
	if (!g()->asset.spr_inverter_idle || \
		!g()->asset.spr_inverter_blue || \
		!g()->asset.spr_inverter_red)
		return (ERROR);
	if (!add_sprite_subimage(g()->asset.spr_inverter_idle, "./res/png/inverter/inverter_blue_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_inverter_blue, "./res/png/inverter/inverter_blue_", 0, 3) || \
		!add_sprite_subimage(g()->asset.spr_inverter_red, "./res/png/inverter/inverter_red_", 0, 3))
		return (ERROR);
	return (OK);
}
