/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:07:00 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_BONUS_H
# define ENGINE_BONUS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"
# include "lib_bonus.h"

# include "engine/engine_list_bonus.h"
# include "engine/engine_image_bonus.h"
# include "engine/engine_instance_bonus.h"
# include "engine/engine_font_bonus.h"
# include "engine/engine_key_bonus.h"
# include "engine/engine_scene_bonus.h"
# include "engine/engine_draw_bonus.h"

# include "asset/asset_bonus.h"

# define DEBUG			0

# define OK				1
# define ERROR			0

# define WINDOW_WIDTH	640
# define WINDOW_HEIGHT	480

# define BUFFER_SIZE	1000 

typedef struct s_asset	t_asset;
typedef struct s_global	t_global;

typedef struct s_view
{
	int				view_wview;
	int				view_hview;
	int				view_xview;
	int				view_yview;
}	t_view;

typedef struct s_frame
{
	int				skip_frame;
	int				count;
}	t_frame;

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
	t_frame			frame;
	int				keys[420];
	char			**ber;
}	t_game;

// game main fucntion
t_game			*g(void);
int				init_game(void);
int				loop(void);
void			start_game(t_scene *scene);

// input function
int				init_input(int ac, char **av);
void			free_input(void);

// util function
int				point_distance(int x1, int y1, int x2, int y2);

#endif
