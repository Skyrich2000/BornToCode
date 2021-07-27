#include "engine.h"

int init_font_fat()
{
	g()->asset.font_fat_xsmall = add_font("./res/png/font/font_fat/8/", 8 + 3);
	g()->asset.font_fat_small = add_font("./res/png/font/font_fat/16/", 16 + 3);
	g()->asset.font_fat_big = add_font("./res/png/font/font_fat/32/", 32 + 5);
	if (!g()->asset.font_fat_xsmall || \
		!g()->asset.font_fat_small || \
		!g()->asset.font_fat_big)
		return (ERROR);
	return (OK);
}
