#include "engine.h"

void		map_1_2(int *width, int *height)
{
	int			out_dir[20];
	char		**map;

	map = sl_split("\
1111111111111111 \
100000Z1000B0001 \
100Z001110B00101 \
100Z00000000B101 \
100Z001111111101 \
1P0Z00Z1E0000001 \
1111111111111111", ' ');

	scr_build_map(map, width, height);
	sl_free_split(map);

	g()->scene->background = g()->asset.background_map_2;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;

	out_dir[SIG_MV_RIGHT] = SIG_MV_RIGHT;
	out_dir[SIG_MV_LEFT] = SIG_MV_LEFT;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(7 * 32, 3 * 32, S_STRAIGHT, out_dir);

	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_UP;
	out_dir[SIG_MV_DOWN] = SIG_MV_DOWN;
	create_inverter_instance(14 * 32, 3 * 32, S_INVERT, out_dir);
}
