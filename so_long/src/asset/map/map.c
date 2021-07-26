#include "engine.h"

int		init_map()
{
	g()->asset.maps[0] = map_0;
	g()->asset.maps[1] = map_1;
	g()->asset.maps[2] = map_2;
	g()->asset.maps[3] = map_3;
	return (OK);
}
