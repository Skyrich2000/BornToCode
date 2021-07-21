/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/07/22 02:12:34 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../src/mlx/mlx.h"
# include "asset.h"
#include "library.h"

# define DEBUG 0

# define OK 1
# define ERROR 0

# define WIDTH 480
# define HEIGHT 320

# define C_RED 0xFF0000
# define C_YELLOW 0xFFFF00
# define C_GREEN 0x00FF00

# define A_LEFT 0
# define A_UP 0
# define A_CENTER 2
# define A_RIGHT 1
# define A_BOTTOM 1

typedef struct s_list
{
	void			*data;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_box
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}	t_box;

typedef struct s_sprite
{
	t_list			*imgs;
	int				width;
	int				height;
	int				img_speed;
	int				offset_x;
	int				offset_y;
	t_box			mask;
}	t_sprite;

typedef struct s_canvas
{
	void			*img;
	void			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}	t_canvas;

// TODO: add space asset
typedef struct s_font
{
	void			*img[127];
	int				width;
	int				height;
}	t_font;

typedef struct s_instance
{
	t_list			*node;
	t_object		obj;
	t_sprite		*spr;
	t_list			*img_node;
	int				draw_time;
	int				x;
	int				y;
	int				dir;
	int				condition;
	void			(*step)(struct s_instance *this);
	void			(*draw)(struct s_instance *this);
}	t_instance;

typedef struct s_scene
{
	t_canvas		*background;
	void			(*start)(void);
	void			(*controller)(void);
	void			(*end)(void);
}	t_scene;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_global		global;
	t_asset			asset;
	t_list			*instances[OBJ_SIZE];
	t_scene			*scene;
	int				keys[420];
}	t_game;

// engine function
t_game		*g();
int			init_game();
int			loop();
void		start_game(t_scene *scene);

int			exit_press(void);
int			key_press(int keycode);
int			key_release(int keycode);

// dev function
t_list		*create_list();
t_list		*push_list(t_list *list, void *data);
void		*pop_list(t_list *node);
void		free_list(t_list *list, void (*del)(void *));

t_font		*add_font(char *path);

t_sprite	*add_sprite(int offset_x, int offset_y, int img_speed, t_box mask);
int			add_sprite_subimage(t_sprite *spr, char *path, int start, int end);
void		delete_sprite(t_sprite *spr);
void		change_sprite(t_instance *id, t_sprite *spr);

t_scene		*add_scene(t_canvas *background, void (*start)(void), void (*controller)(void), void (*end)(void));
void		scene_default_end();

// user usable function
int			keyboard_check(int keycode);

t_instance  *create_instance(t_sprite *spr, int data[3], void (*step)(t_instance *this), void (*draw)(t_instance *this));
int			point_distance(int x1, int y1, int x2, int y2);
int			place_meeting(t_instance *id, int x, int y, t_instance *other);
t_instance	*place_meeting_type(t_instance *id, int x, int y, int type);
void		destroy_instance(t_instance *id);

void		draw_line(int pos[2], int dir[2], int len, int color);
void		draw_box(t_box	box, int color);
void		draw_point(int x, int y, int color);
void		draw_debug();
void		draw_img(void *img, int x, int y);
void		draw_sprite(t_sprite *spr, t_list *img_node, int x, int y);
void		draw_background(t_canvas *background);
void		draw_font(t_font *font, char *str, int pos[2], int align[2]);

void		scene_start();
void		scene_restart();
void		scene_end();

#endif
