#include "engine.h"

int init_font_su()
{
	g()->asset.font_su = add_font("./res/png/font/font_su/", 40);
	if (!g()->asset.font_su)
		return (ERROR);
	return (OK);
}
