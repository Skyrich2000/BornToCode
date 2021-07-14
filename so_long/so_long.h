#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_img
{
	void	*img;
	int		width;
	int		height;
}				t_img;

typedef struct		s_list
{
	void			*data;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

typedef struct		s_sprite
{
	t_list			*imgs;
	int				subimg;
	int				offset_x;
	int				offset_y;
}					t_sprite;

typedef struct		s_instance
{
	t_sprite		*spr;
	int				image_index;
}					t_instance;

typedef struct	s_canvas
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_canvas;

typedef struct	s_game
{
	void			*mlx;
	void			*win;

	t_canvas		canvas;
	int				width;
	int				height;

	t_sprite		spr_player;
	t_sprite		spr_zombie;
	t_sprite		spr_wall;
	t_sprite		spr_key;
	t_sprite		spr_exit;

	t_obj_player	obj_player;
	t_obj_zombie	obj_zombie;
	t_obj_wall		obj_wall;
	t_obj_key		obj_key;
	t_obj_exit		obj_exit;
}				t_game;

t_sprite	*create_sprite(char *path);

void		draw_sprite(t_sprite *spr, int subimg, int x, int y);

void		draw();

#endif
