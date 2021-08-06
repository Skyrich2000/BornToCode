#include "engine.h"

int		init_map()
{
	g()->asset.maps[0] = map_0;
	g()->asset.maps[1] = map_1_2;
	g()->asset.maps[2] = map_1_3;
	g()->asset.maps[3] = map_2;
	g()->asset.maps[4] = map_3;
	g()->asset.maps[5] = map_4;
	g()->asset.maps[6] = map_5;
	return (OK);
}
