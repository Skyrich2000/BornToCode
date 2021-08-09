#include "engine.h"

void		map_0_1(int *width, int *height)
{
	char		**map;
	int			out_dir[20];

	map = sl_split("\
1111111111111111 \
10000000000000E1 \
1011111111111111 \
1000000000000001 \
1111111111111101 \
100C0000C000C101 \
1000000000000101 \
1P0000C000C000C1 \
1111111111111111", ' ');

	scr_build_map(map, width, height);
	sl_free_split(map);

	g()->scene->background = g()->asset.background_map_2;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;
	g()->global.tutorial = 1;

	out_dir[SIG_MV_RIGHT] = SIG_MV_DOWN;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_LEFT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(14 * 32, 3 * 32, S_STRAIGHT, out_dir);

	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = SIG_MV_DOWN;
	out_dir[SIG_MV_UP] = SIG_MV_RIGHT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(1 * 32, 1 * 32, S_INVERT, out_dir);

}
