#include "engine.h"

int init_font_su()
{
	g()->asset.font_su = add_font("./res/png/font/font_su/", 40);
	if (!g()->asset.font_su)
		return (ERROR);
	return (OK);
}

int init_font_fat()
{
	g()->asset.font_fat_small = add_font("./res/png/font/font_fat/32/", 32);
	g()->asset.font_fat_big = add_font("./res/png/font/font_fat/64/", 64);
	if (!g()->asset.font_fat_small || \
		!g()->asset.font_fat_big)
		return (ERROR);
	return (OK);
}