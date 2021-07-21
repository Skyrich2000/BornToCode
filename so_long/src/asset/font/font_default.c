#include "engine.h"

int init_font_default()
{
	g()->asset.font_default = add_font("./res/xpm/font/");
	if (!g()->asset.font_default)
		return (ERROR);
	return (OK);
}
