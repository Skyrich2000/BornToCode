#ifndef SO_LONG_H
# define SO_LONG_H

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

typedef struct		s_obj_player
{
	int				hp;
}					t_obj_player;

typedef struct		s_obj_zombie
{
	int				hp;
}					t_obj_zombie;

typedef union		u_object
{
	t_obj_player	player;
	t_obj_zombie	zombie;
}					t_object;

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

	t_sprite		*spr_player_idle;
	t_sprite		*spr_player_move_right;
	t_sprite		*spr_zombie;
	t_sprite		*spr_wall;
	t_sprite		*spr_key;
	t_sprite		*spr_exit;

	t_list			*instances;
}					t_game;

t_list		*create_list();
int			push_list(t_list *list, void *data);
void		free_list(t_list *list, void (*del)(void *));

t_sprite	*create_sprite();
int			add_subimage(t_sprite *spr, char *path);
void		set_sprite_offset(int offset_x, int offset_y);
void		delete_sprite(t_sprite *spr);


t_instance	*create_player_instance(int x, int y);
void		obj_player_step(t_instance *this);
void		obj_player_draw(t_instance *this);
void		destroy_instance(void *id);

void		draw_sprite(t_sprite *spr, int subimg, int x, int y);

void		reset_canvas();
int			loop(void *param);
void		draw();

#endif
