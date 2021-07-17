/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 04:07:03 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../srcs/mlx/mlx.h"
# include "asset.h"
#include "library.h"

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
	int				img_speed;
	int				offset_x;
	int				offset_y;
}					t_sprite;

typedef struct		s_instance
{
	int				type;
	t_object		obj;
	t_sprite		*spr;
	t_list			*img_node;
	int				img_speed;
	int				draw_time;
	int				x;
	int				y;
	int				dir;
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

typedef struct		s_scene
{
	t_canvas		*background;
	void			(*start)(void);
	void			(*end)(void);
}					t_scene;

typedef struct		s_game
{
	void			*mlx;
	void			*win;
	t_global		global;
	t_asset			asset;
	t_list			*instances[OBJ_SIZE];
	t_scene			*scene;
	int				keys[127];
}					t_game;

// core engine function
t_game		*g();
void		init_game();
int			loop();
int			exit_press(void);
int			key_press(int keycode);
int			key_release(int keycode);
void		scene_end();
void		start_game(t_scene *scene);

// dev function
t_list		*create_list();
int			push_list(t_list *list, void *data);
void		free_list(t_list *list, void (*del)(void *));

t_sprite	*add_sprite(int offset_x, int offset_y, int img_speed);
int			add_sprite_subimage(t_sprite *spr, char *path);
void		delete_sprite(t_sprite *spr);
void		change_sprite(t_instance *id, t_sprite *spr);

t_scene		*add_scene(t_canvas *background, void (*init)(void));
void		delete_scene(t_scene *scene);

// user usable function
int			keyboard_check(int keycode);

t_instance  *create_instance(t_sprite *spr, int data[3], void (*step)(t_instance *this), void (*draw)(t_instance *this));
t_instance	*get_instance(int type);
void		destroy_instance(void *id);

void		draw_sprite(t_sprite *spr, t_list *img_node, int x, int y);
void		draw_background();

// debug
void	print_footprint();
#endif
