/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 04:09:48 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_H
# define ASSET_H
# include "engine.h"

# define ZOMBIE 0
# define WALL 1
# define KEY 2
# define EXIT 3
# define AVATAR 4
# define PLAYER 5
# define OBJ_SIZE 6
# define INS_MAX 100

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13
# define KEY_SPACEBAR		49
# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126
# define KEY_I				34

typedef struct		s_canvas t_canvas;
typedef struct		s_scene t_scene;
typedef struct		s_sprite t_sprite;
typedef struct		s_instance t_instance;
typedef struct		s_list t_list;

typedef struct		s_global
{
	t_list			*straight;
	t_list			*reverse;
	int				steps;
	int				deathcount;
	int				inverted;
	int				status;
}					t_global;

typedef struct		s_footprint
{
	int				x;
	int				y;
	void			*img;
}					t_footprint;

typedef struct		s_obj_player
{
	int				hp;
	int				attack;
	int				h_mv;
	int				v_mv;
	int				prev_x;
	int				prev_y;
}					t_obj_player;

typedef struct		s_obj_avatar
{
	t_list			*node;
}					t_obj_avatar;

typedef struct		s_obj_zombie
{
	int				hp;
}					t_obj_zombie;

typedef union		u_object
{
	t_obj_player	player;
	t_obj_zombie	zombie;
	t_obj_avatar	avatar;
}					t_object;

typedef struct		s_asset
{
	t_canvas		*background_black;

	t_sprite		*spr_player_idle_right;
	t_sprite		*spr_player_idle_left;
	t_sprite		*spr_player_move_right;
	t_sprite		*spr_player_move_left;
	t_sprite		*spr_player_attack_right;
	t_sprite		*spr_player_attack_left;
	t_sprite		*spr_player_die_right;
	t_sprite		*spr_player_die_left;

	t_sprite		*spr_player_idle_right_reverse;
	t_sprite		*spr_player_idle_left_reverse;
	t_sprite		*spr_player_move_right_reverse;
	t_sprite		*spr_player_move_left_reverse;
	t_sprite		*spr_player_attack_right_reverse;
	t_sprite		*spr_player_attack_left_reverse;
	t_sprite		*spr_player_die_right_reverse;
	t_sprite		*spr_player_die_left_reverse;

	t_sprite		*spr_zombie_idle_right;
	t_sprite		*spr_zombie_idle_left;
	t_sprite		*spr_zombie_die_right;
	t_sprite		*spr_zombie_die_left;

	t_sprite		*spr_zombie_idle_right_reverse;
	t_sprite		*spr_zombie_idle_left_reverse;
	t_sprite		*spr_zombie_die_right_reverse;
	t_sprite		*spr_zombie_die_left_reverse;

	t_sprite		*spr_wall;
	t_sprite		*spr_key;
	t_sprite		*spr_exit;

	t_scene			*scene_main;
	t_scene			*scene_tutorial;
	t_scene			*scene_mandatory;
	t_scene			*scene_play;
	t_scene			*scene_rank;
}					t_asset;

int			init_asset();
void		free_asset();

//background
int			init_background_black();

// sprite
int			init_spr_player();
int			init_spr_zombie();
int			init_spr_wall();
int			init_spr_key();
int			init_spr_exit();

// object
t_instance	*create_player_instance(int x, int y);
void		obj_player_step(t_instance *this);
void		obj_player_draw(t_instance *this);

t_instance	*create_zombie_instance(int x, int y);
void		obj_zombie_draw(t_instance *this);

t_instance	*create_avatar_instance(t_list *route, int dir);
void		obj_avatar_step(t_instance *this);
void		obj_avatar_draw(t_instance *this);

// scene
int			init_scene_play();
void		scene_play_start();
void		scene_play_controller();
void		scene_play_end();

#endif
