#include "engine.h"

void		map_0(int *width, int *height)
{
	scr_build_map(g()->ber, width, height);

	g()->scene->background = g()->asset.background_map_2;
	g()->global.state = S_STRAIGHT;
	g()->global.invert_signal = SIG_NO_INVERT;
}
