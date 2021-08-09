#include "engine.h"

void		map_0_0(int *width, int *height)
{
	scr_build_map(g()->ber, width, height);

	g()->global.player->signal = SIG_MV_AUTO | SIG_DIR_RIGHT;

	g()->scene->background = g()->asset.background_map_2;
	g()->global.state = S_READY;
	g()->global.invert_signal = SIG_NO_INVERT;
	g()->global.tutorial = 1;
}
