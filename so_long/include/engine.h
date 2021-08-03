/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 17:03:26 by ycha             ###   ########.fr       */
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

# define DEBUG			0

# define OK				1
# define ERROR			0

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	480

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_R			15
# define KEY_SPACEBAR	49
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_I			34
# define KEY_P			35
# define KEY_ENTER		36
# define KEY_BACKSPACE	51

# define C_RED			0xFF0000
# define C_YELLOW		0xFFFF00
# define C_GREEN		0x00FF00
# define C_BLUE			0x0000FF

# define A_LEFT			0.0f
# define A_UP			0.0f
# define A_CENTER		0.5f
# define A_RIGHT		1.0f
# define A_BOTTOM		1.0f

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

typedef struct s_background
{
	void			*img;
	int				x;
	int				y;
	int				width;
	int				height;
}				t_background;

typedef struct s_font
{
	void			*img[127];
	int				size;
	int				real_size;
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
	int				signal;
	void			(*step)(struct s_instance *this);
	void			(*draw)(struct s_instance *this);
}	t_instance;

typedef struct s_scene
{
	t_background	*background;
	void			(*start)(void);
	void			(*controller)(void);
	void			(*ui)(void);
	void			(*end)(void);
}	t_scene;

typedef struct s_view
{
	int				view_wview;
	int				view_hview;
	int				view_xview;
	int				view_yview;
}	t_view;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_background	canvas;
	t_global		global;
	t_asset			asset;
	t_list			*instances[OBJ_SIZE];
	t_scene			*scene;
	t_view			view;
	char			**ber;
	int				keys[420];
}	t_game;

/* ************************************************************************** */

// gmae main fucntion
t_game		*g();
int			init_game();
int			loop();
void		start_game(t_scene *scene);
// input function
int			init_input(int ac, char **av);
void		free_input();
// key hook function
int			exit_press(void);
int			key_press(int keycode);
int			key_release(int keycode);

/* ************************************************************************** */

// list function
t_list		*create_list();
t_list		*push_list(t_list *list, void *data);
void		*pop_list(t_list *node);
void		free_list(t_list *list, void (*del)(void *));
// manage font asset
t_font		*add_font(char *path, int size);
// manage image asset
t_sprite	*add_sprite(int offset_x, int offset_y, int img_speed, t_box mask);
t_background	*add_background(char *path, int x, int y);
int			add_sprite_subimage(t_sprite *spr, char *path, int start, int end);
// manage scene asset
t_scene		*add_scene(t_background *background, void (*start)(void), void (*controller)(void), void (*ui)(void), void (*end)(void));

/* ************************************************************************** */

// check if keyboard is press
int			keyboard_check(int keycode);
// sprite function
void		change_sprite(t_instance *id, t_sprite *spr);
// instance function
t_instance  *create_instance(t_sprite *spr, int data[3], void (*step)(t_instance *this), void (*draw)(t_instance *this));
int			place_meeting(t_instance *id, int x, int y, t_instance *other);
t_instance	*place_meeting_type(t_instance *id, int x, int y, int type);
void		destroy_instance(t_instance *id);
void		destroy_all_instance();
// math function
int			point_distance(int x1, int y1, int x2, int y2);
// draw function
void		draw_img(void *img, int x, int y);
void		draw_sprite(t_sprite *spr, t_list *img_node, int x, int y);
void		draw_background(t_background *background);
void		draw_text(t_font *font, char *str, int pos[2], float align[2]);
// draw function for debug
void		draw_point(int x, int y, int color);
void		draw_bold_point(int x, int y, int color);
void		draw_line(int pos[2], int dir[2], int len, int color);
void		draw_box(t_box	box, int color);
void		draw_debug();
// scene manage function
void		scene_start();
void		scene_change(t_scene *scene);
void		scene_restart();
void		scene_end();

#endif
