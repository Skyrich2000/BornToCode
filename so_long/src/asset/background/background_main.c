#include "engine.h"

int		init_background_main()
{
	g()->asset.background_main = add_background("./res/png/background/background_main_0.png", 0, 0);
	if (!g()->asset.background_main)
		return (ERROR);
	return (OK);
}
