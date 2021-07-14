#include "so_long.h"
#include <stdio.h>
#include "mlx/mlx.h"

t_list	*create_list()
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (ERROR);
	new->prev = 0;
	new->next = 0;
	return (new);
}

int		push_list(t_list *list, void *data)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (ERROR);
	new->prev = list;
	new->next = list->next;
	new->next->prev = new;
	new->prev->next = new;
	return (OK);
}

void	free_list(t_list *list, void (*del)(void *))
{
	if (list->next)
		free_list(list->next);
	if (del)
		del(list->data);
	free(list);
}

t_game	*g()
{
	static t_game game;

	return (&game);
}

void	init_game()
{
	t_game *game;

	game = g();
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "my game");
	game->instances = create_list();
}

void	reset_canvas()
{
	t_game *game;

	game = g();
	game->canvas.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->canvas.data = mlx_get_data_addr(game->canvas.img, &game->canvas.bits_per_pixel, &game->canvas.line_length, &game->canvas.endian);
}

void	loop()
{
	t_list *node;

	node = g()->instances->next;
	while (node->next)
	{
		node->step();
		node = node->next;
	}

	node = g()->instances->next;
	while (node->next)
	{
		node->draw();
		node = node->next;
	}
}

t_sprite	*create_sprite()
{
	t_sprite *new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	new->imgs = create_list();
	if (!new->imgs)
		return (ERROR);
	new->offset_x = 0;
	new->offset_y = 0;
	return (new);
}

int			add_subimage(t_sprite *spr, char *path)
{
	void	*img;

	spr->subimg++;
	img = mlx_xpm_file_to_image(g()->mlx, path, spr->width, spr->height);
	return (push_list(spr.imgs, img));
}

void		delete_sprite(t_sprite *spr)
{
	free_list(spr->imgs, 0);
	free(spr);
}

t_instance	*create_player_instance(int x, int y)
{
	t_instance *new;

	new = (t_instance *)malloc()
	if (!new)
		return (ERROR);
	new->type = 0;
	new->obj.player.hp = 0;
	new->spr = g()->spr_player_idle;
	new->img_node = new->spr->imgs->next;
	new->x = x;
	new->y = y;
	new->step = obj_player_step;
	new->draw = obj_player_draw;
	return (new);
}

void		obj_player_step(t_instance *this)
{
	this->img_node = this->img_node->next;
}

void		obj_player_draw(t_instance *this)
{
	mlx_put_image_to_window(g()->mlx, g()->win, this->img_node->data, this->x, this->y);
}

int main()
{
	t_game *game;

	game = g();
	init_game();

	game->spr_player_idle = create_sprite();
	add_subimage(game->spr_player_idle, "xpm/player_8.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_7.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_6.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_5.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_4.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_3.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_2.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_1.xpm");
	add_subimage(game->spr_player_idle, "xpm/player_0.xpm");

	t_instance	*player;
	player = create_player_instance(50, 50);

	mlx_loop_hook(game->mlx, loop, 0);
	mlx_loop(mlx);

	delete_sprite(&game->spr_player);
	return (0);
}
