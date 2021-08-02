#include "engine.h"

int			init_spr_state()
{
	g()->asset.spr_ready = add_sprite(0, 0, 0, (t_box){ 0, 0, 0, 0 });
	g()->asset.spr_straight = add_sprite(0, 0, 0, (t_box){ 0, 0, 0, 0 });
	g()->asset.spr_invert = add_sprite(0, 0, 0, (t_box){ 0, 0, 0, 0 });
	g()->asset.spr_clear = add_sprite(0, 0, 0, (t_box){ 0, 0, 0, 0 });
	g()->asset.spr_gameover = add_sprite(0, 0, 0, (t_box){ 0, 0, 0, 0 });
	if (!add_sprite_subimage(g()->asset.spr_ready, "./res/png/state/ready_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_straight, "./res/png/state/straight_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_invert, "./res/png/state/invert_", 0, 0) ||
		!add_sprite_subimage(g()->asset.spr_clear, "./res/png/state/clear_", 0, 0) || \
		!add_sprite_subimage(g()->asset.spr_gameover, "./res/png/state/gameover_", 0, 0))
		return (ERROR);
	return (OK);
}
