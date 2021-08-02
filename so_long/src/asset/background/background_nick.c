#include "engine.h"

int		init_background_nick()
{
	g()->asset.background_nick = add_background("./res/png/background/background_main_0.png", 0, 0);
	return (OK);
}
