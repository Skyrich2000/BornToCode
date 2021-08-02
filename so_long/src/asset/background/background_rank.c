#include "engine.h"

int		init_background_rank()
{
	g()->asset.background_rank = add_background("./res/png/empty_0.png", 0, 0);
	return (OK);
}
