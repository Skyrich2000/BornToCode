#include "engine.h"

int		init_background_nick()
{
	g()->asset.background_nick = add_background("./res/png/background/background_main_0.png", 0, 0);
	if (!g()->asset.background_nick)
		return (ERROR);
	return (OK);
}
