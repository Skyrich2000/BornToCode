#include "engine.h"

int		init_background_black()
{
	t_canvas	*new;

	new = (t_canvas *)malloc(sizeof(t_canvas));
	if (!new)
		return (ERROR);
	new->img = mlx_new_image(g()->mlx, WIDTH, HEIGHT);
	new->addr = mlx_get_data_addr(new->img, &new->bits_per_pixel, &new->line_length, &new->endian);
	g()->asset.background_black = new;
	return (OK);
}
