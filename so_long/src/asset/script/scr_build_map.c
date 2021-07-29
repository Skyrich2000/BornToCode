#include "engine.h"

void		scr_build_map(char **map, int *width, int *height)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
			{
				create_wall_instance(j * 32, i * 32);
				create_wall_up_instance(j * 32, i * 32);
			}
			else if (map[i][j] == 'Z')
				create_zombie_instance(j * 32, i * 32);
			else if (map[i][j] == 'B')
				create_box_instance(j * 32, i * 32);
			else if (map[i][j] == 'C')
			{
				g()->global.gold_num++;
				create_gold_instance(j * 32, i * 32);
			}
			else if (map[i][j] == 'P')
				g()->global.player = create_player_instance(j * 32, i * 32, S_STRAIGHT);
			else if (map[i][j] == 'E')
				create_exit_instance(j * 32, i * 32);
		}
	}
	*height = i;
	*width = j;
}
