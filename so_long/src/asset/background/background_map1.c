#include "engine.h"

int		init_background_map1()
{
	t_background *new;

	new = (t_background *)malloc(sizeof(t_background));
	if (!new)
		return (ERROR);
	new->img = mlx_png_file_to_image(g()->mlx, "./res/png/background/background_1.png", &new->width, &new->height);
	new->x = -16;
	new->y = -32;
	g()->asset.background_map1 = new;
	return (OK);
}
