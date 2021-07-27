#include "engine.h"

void		scr_build_map(char **map)
{
	int i;
	int j;

	i = -1;
	while (++i < 7)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				create_wall_instance(j * 32, i * 32);
			else if (map[i][j] == 'z')
				create_zombie_instance(j * 32, i * 32);
			else if (map[i][j] == 'b')
				create_box_instance(j * 32, i * 32);
			else if (map[i][j] == 'g')
				create_gold_instance(j * 32, i * 32);
			else if (map[i][j] == 'p')
				g()->global.player = create_player_instance(j * 32, i * 32, S_STRAIGHT);
		}
	}
}
