#include "engine.h"

void		map_0()
{
	t_instance	*ins;
	int			out_dir[20];
	char		**map;

	map = sl_split("\
11111111111111 \
10000010000001 \
10111011011101 \
1011100zb11101 \
10111011001101 \
10p0000e1g0001 \
11111111111111", ' ');

	scr_build_map(map);
	sl_free_split(map);

	g()->scene->background = g()->asset.background_map_0;
	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;

	out_dir[SIG_MV_RIGHT] = SIG_MV_DOWN;
	out_dir[SIG_MV_LEFT] = 0;
	out_dir[SIG_MV_UP] = SIG_MV_LEFT;
	out_dir[SIG_MV_DOWN] = 0;
	create_inverter_instance(12 * 32, 1 * 32, S_STRAIGHT, out_dir);

	out_dir[SIG_MV_RIGHT] = 0;
	out_dir[SIG_MV_LEFT] = SIG_MV_UP;
	out_dir[SIG_MV_UP] = 0;
	out_dir[SIG_MV_DOWN] = SIG_MV_RIGHT;
	create_inverter_instance(1 * 32, 5 * 32, S_INVERT, out_dir);

	ins = create_dummy_instance(1 * 32, 5 * 32, S_STRAIGHT, 60);
	ins->signal = SIG_MV_AUTO | SIG_MV_RIGHT | SIG_DIR_RIGHT;
	ins = create_dummy_instance(1 * 32, 5 * 32, S_INVERT, 60);
	ins->signal = SIG_MV_AUTO | SIG_MV_UP | SIG_DIR_RIGHT;
}
