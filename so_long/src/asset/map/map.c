#include "engine.h"

int		init_map()
{
	g()->asset.maps[0] = map_0_3;
	g()->asset.maps[1] = map_0_1;
	g()->asset.maps[2] = map_0_2;
	g()->asset.maps[3] = map_0_3;
	g()->asset.maps[4] = map_0_4;
	g()->asset.maps[5] = map_0_5;
	g()->asset.maps[6] = map_0_6;
	g()->asset.maps[7] = map_1;
	g()->asset.maps[8] = map_2;
	g()->asset.maps[9] = map_3;
	g()->asset.maps[10] = map_4;
	g()->asset.maps[11] = map_5;
	return (OK);
}
