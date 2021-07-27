#include "engine.h"

int		init_background_menu()
{
	g()->asset.background_menu = add_background("./res/png/background/background_1.png", -16, -32);
	if (!g()->asset.background_menu)
		return (ERROR);
	return (OK);
}
