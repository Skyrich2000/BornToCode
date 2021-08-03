#include "engine.h"

void		map_2(int *width, int *height)
{
	t_instance	*ins;
	int			out_dir[20];
	char		**map;

	map = sl_split("\
11111111111 \
10000010001 \
1P111010101 \
10100BC0101 \
10101C11101 \
100E1000001 \
11111111111", ' ');

	scr_build_map(map, width, height);
	sl_free_split(map);

	g()->scene->background = g()->asset.background_map_1;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;

	out_dir[SIG_MV_RIGHT] = SIG_MV_UP;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = SIG_MV_LEFT;
	create_inverter_instance(9 * 32, 5 * 32, S_STRAIGHT, out_dir);

	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = SIG_MV_DOWN;
	out_dir[SIG_MV_UP] = SIG_MV_RIGHT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(1 * 32, 1 * 32, S_INVERT, out_dir);

	ins = create_dummy_instance(1 * 32, 1 * 32, S_STRAIGHT, 60);
	ins->signal = SIG_MV_AUTO | SIG_MV_DOWN | SIG_DIR_RIGHT;
	ins = create_dummy_instance(1 * 32, 1 * 32, S_INVERT, 60);
	ins->signal = SIG_MV_AUTO | SIG_MV_RIGHT | SIG_DIR_RIGHT;
}
