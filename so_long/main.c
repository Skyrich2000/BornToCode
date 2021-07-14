#include "so_long.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx/mlx.h"

time_t start;

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
	new->data = data;
	new->prev = list;
	new->next = list->next;
	if (new->next)
		new->next->prev = new;
	new->prev->next = new;
	return (OK);
}

void	free_list(t_list *list, void (*del)(void *))
{
	if (list->next)
		free_list(list->next, del);
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

// static void	put_pixel(t_minirt *mini, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = mini->curr_cam->img_addr + \
// 		(y * mini->scr.line_length + x * (mini->scr.bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	reset_canvas()
{
	t_canvas can;

	can.img = mlx_new_image(g()->mlx, WIDTH, HEIGHT);
	can.addr = mlx_get_data_addr(can.img, &can.bits_per_pixel, &can.line_length, &can.endian);
	mlx_put_image_to_window(g()->mlx, g()->win, can.img, 0, 0);
}

int		loop(void *param)
{
	static int fps = 0;
	time_t end;
	t_list *node;
	t_instance	*ins;

	fps++;
	time(&end);
	if ((float)(end - start) >= 1.0)
	{
		printf("fps : %d\n", fps);
		fps = 0;
		time(&start);
	}

	node = g()->instances->next;
	while (node)
	{
		ins = (t_instance *)node->data;
		ins->step(ins);
		node = node->next;
		
	}

	reset_canvas();
	node = g()->instances->next;
	while (node)
	{
		ins = (t_instance *)node->data;
		ins->draw(ins);
		node = node->next;
	}
	return (OK);
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
	img = mlx_xpm_file_to_image(g()->mlx, path, &spr->width, &spr->height);
	return (push_list(spr->imgs, img));
}

void		delete_sprite(t_sprite *spr)
{
	free_list(spr->imgs, 0);
	free(spr);
}

t_instance	*create_player_instance(int x, int y)
{
	t_instance *new;

	new = (t_instance *)malloc(sizeof(t_instance));
	if (!new)
		return (ERROR);
	new->type = 0;
	new->obj.player.hp = 0;
	new->spr = g()->spr_player_idle;
	new->img_node = new->spr->imgs->next;
	new->img_speed = 5;
	new->x = x;
	new->y = y;
	new->step = obj_player_step;
	new->draw = obj_player_draw;
	if (!push_list(g()->instances, new))
		return (ERROR);
	return (new);
}

void		obj_player_step(t_instance *this)
{
	static int time = 0;
	static int mv = 0;
	
	time++;
	if (time > 120)
	{
		if (mv == 0) // if stop
		{
			this->spr = g()->spr_player_move_right;
			this->img_node = this->spr->imgs->next;
			mv = 1; // go right
		}
		else if (mv == 1) // if going right
		{
			this->spr = g()->spr_player_idle;
			this->img_node = this->spr->imgs->next;
			mv = 0; // stop
		}
		time = 0;
	}

	if (mv)
		this->x += 1;
}

void		obj_player_draw(t_instance *this)
{
	static int time = 0;

	mlx_put_image_to_window(g()->mlx, g()->win, this->img_node->data, this->x + this->spr->offset_x, this->y + this->spr->offset_y);
	time++;
	if (time > this->img_speed)
	{
		this->img_node = this->img_node->next;
		time = 0;
	}
	if (!this->img_node)
		this->img_node = this->spr->imgs->next;
}

int main()
{
	t_game *game;

	game = g();
	init_game();

	game->spr_player_idle = create_sprite();
	add_subimage(game->spr_player_idle, "./xpm/player_8.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_7.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_6.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_5.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_4.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_3.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_2.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_1.xpm");
	add_subimage(game->spr_player_idle, "./xpm/player_0.xpm");

	game->spr_player_move_right = create_sprite();
	add_subimage(game->spr_player_move_right, "./xpm/player_14.xpm");
	add_subimage(game->spr_player_move_right, "./xpm/player_13.xpm");
	add_subimage(game->spr_player_move_right, "./xpm/player_12.xpm");
	add_subimage(game->spr_player_move_right, "./xpm/player_11.xpm");
	add_subimage(game->spr_player_move_right, "./xpm/player_10.xpm");
	add_subimage(game->spr_player_move_right, "./xpm/player_9.xpm");

	t_instance	*player;
	player = create_player_instance(50, 50);
	printf("done! player %p\n", player);

	time(&start);
	mlx_loop_hook(game->mlx, loop, 0);
	mlx_loop(game->mlx);

	delete_sprite(game->spr_player_idle);
	return (0);
}
