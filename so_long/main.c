#include "so_long.h"
#include <stdio.h>
#include "mlx/mlx.h"

t_game	*g()
{
	static t_game game;

	return (&game);
}

void	init_game(int width, int height, char *title)
{
	g()->mlx = mlx_init();
	g()->win = mlx_new_window(game->mlx, width, height, title);
	g()->width = width;
	g()->height = height;
}

void	reset_canvas()
{
	g()->canvas.img = mlx_new_image(g()->mlx, g()->width, g()->height);
	g()->canvas.data = mlx_get_data_addr(g()->canvas.img, &g()->canvas.bits_per_pixel, &g()->canvas.line_length, &g()->canvas.endian);
}

void	draw()
{
	img = mlx_xpm_file_to_image(mlx, "xpm/player_0.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 50, 50);
}

void	loop()
{
	step();
	draw();
}

int main()
{
	init_game(500, 500, "animation gogo");
	
	g()->spr_player = create_sprite();
	add_image(g()->spr_player, "");

	g()->obj_player = create_object(g()->spr_player);

	create_instance()

	mlx_loop_hook(g()->mlx, loop, 0);
	mlx_loop(mlx);
	return (0);
}
