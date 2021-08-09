#include "engine.h"

void		map_0_5(int *width, int *height)
{
	int			out_dir[20];
	char		**map;

	map = sl_split("\
11111111111111111 \
10000500100000001 \
10040501110030101 \
10040C000000Z0101 \
100B0C01111111101 \
1P0B00001E0000001 \
11111111111111111", ' ');

	scr_build_map(map, width, height);
	sl_free_split(map);

	g()->scene->background = g()->asset.background_map_2;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;
	g()->global.tutorial = 1;

	out_dir[SIG_MV_RIGHT] = SIG_MV_RIGHT;
	out_dir[SIG_MV_LEFT] = SIG_MV_LEFT;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(8 * 32, 3 * 32, S_STRAIGHT, out_dir);

	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_UP;
	out_dir[SIG_MV_DOWN] = SIG_MV_DOWN;
	create_inverter_instance(15 * 32, 3 * 32, S_INVERT, out_dir);
}
