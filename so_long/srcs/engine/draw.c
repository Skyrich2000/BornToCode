#include "engine.h"

void	draw_background()
{
	mlx_put_image_to_window(g()->mlx, g()->win, g()->background.img, 0, 0);
}

void	draw_sprite(t_sprite *spr, t_list *img_node, int x, int y)
{
	mlx_put_image_to_window(g()->mlx, g()->win, img_node->data, x + spr->offset_x, y + spr->offset_y);
}
