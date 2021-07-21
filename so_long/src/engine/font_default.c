#include "engine.h"

int init_font_default()
{
	return (g()->asset.font_default = add_font("./res/xpm/font/"));
}
