#include "engine.h"

int		init_background_map()
{
	g()->asset.background_map_0 = add_background("./res/png/background/background_0.png", -16, -32);
	g()->asset.background_map_1 = add_background("./res/png/background/background_1.png", -16, -32);
	g()->asset.background_map_2 = add_background("./res/png/background/background_2.png", -16, -32);
	return (OK);
}
