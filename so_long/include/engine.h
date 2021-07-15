#ifndef ENGINE_H
# define ENGINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../srcs/mlx/mlx.h"
# include "asset.h"

# define OK 1
# define ERROR 0

# define WIDTH 600
# define HEIGHT 300

typedef struct		s_list
{
	void			*data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_sprite
{
	t_list			*imgs;
	int				width;
	int				height;
	int				subimg;
	int				offset_x;
	int				offset_y;
}					t_sprite;

typedef struct		s_instance
{
	int 			type;
	t_object		obj;
	t_sprite		*spr;
	t_list			*img_node;
	int				img_speed;
	int				x;
	int				y;
	void			(*step)(struct s_instance *this);
	void			(*draw)(struct s_instance *this);
}					t_instance;

typedef struct		s_canvas
{
	void			*img;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_canvas;

typedef struct		s_game
{
	void			*mlx;
	void			*win;
`	t_asset			asset;
	t_canvas		background;
	t_list			*instances;
}					t_game;

t_list		*create_list();
int			push_list(t_list *list, void *data);
void		free_list(t_list *list, void (*del)(void *));

t_sprite	*add_sprite();
int			add_sprite_subimage(t_sprite *spr, char *path);
void		set_sprite_offset(int offset_x, int offset_y);
void		delete_sprite(t_sprite *spr);

void		destroy_instance(void *id);
void		draw_sprite(t_sprite *spr, t_list *img_node, int x, int y);
void		draw_background();

t_game		*g();
void		init_game();
int			loop(void *param);
void		start_game();

#endif
