#include "engine.h"

int		init_background_map()
{
	g()->asset.background_map_0 = add_background("./res/png/background/background_1.png", -16, -32);
	g()->asset.background_map_1 = add_background("./res/png/background/background_1.png", -16, -32);
	g()->asset.background_map_2 = add_background("./res/png/background/background_1.png", -16, -32);
	g()->asset.background_map_3 = add_background("./res/png/background/background_1.png", -16, -32);
	if (!g()->asset.background_map_0 || \
		!g()->asset.background_map_1 || \
		!g()->asset.background_map_2 || \
		!g()->asset.background_map_3)
		return (ERROR);
	return (OK);
}

int		init_background_main()
{
	g()->asset.background_main = add_background("./res/png/background/background_main_0.png", -16, -32);
	if (!g()->asset.background_main)
		return (ERROR);
	return (OK);
}


int		init_background_default()
{
	g()->asset.background_default = add_background("./res/png/background/background_1.png", -16, -32);
	if (!g()->asset.background_default)
		return (ERROR);
	return (OK);
}
