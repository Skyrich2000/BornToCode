#include "engine.h"

void		map_1(int *width, int *height)
{
	char		**map;
	int			out_dir[20];

	map = sl_split("\
1111111111111111 \
1000000000000001 \
1011111111111101 \
1010001000B000C1 \
1010101011111101 \
101010100B00B011 \
1010101110111001 \
10001E1P000B00B1 \
1111111111111111", ' ');

	scr_build_map(map, width, height);
	sl_free_split(map);

	g()->scene->background = g()->asset.background_map_2;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;

	out_dir[SIG_MV_RIGHT] = SIG_MV_RIGHT;
	out_dir[SIG_MV_LEFT] = SIG_MV_LEFT;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(6 * 32, 1 * 32, S_STRAIGHT, out_dir);

	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_UP;
	out_dir[SIG_MV_DOWN] = SIG_MV_DOWN;
	create_inverter_instance(3 * 32, 5 * 32, S_INVERT, out_dir);
}
