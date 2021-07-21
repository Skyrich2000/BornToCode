/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/07/22 04:18:14 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_H
# define ASSET_H
# include "engine.h"

# define WALL				0
# define BOX				1
# define KEY				2
# define EXIT				3
# define ZOMBIE				4
# define PLAYER				5
# define OBJ_SIZE			6

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
# define KEY_P				35

# define C_DEAD				1
# define C_DEING			2
# define C_ALIVE			4
# define C_AVATAR			8

# define S_STRAIGHT			0
# define S_INVERT			1
# define S_RESTRAIGHT		2
# define S_GAMEOVER			3
# define S_CLEAR			4

typedef struct s_canvas		t_canvas;
typedef struct s_scene		t_scene;
typedef struct s_sprite		t_sprite;
typedef struct s_instance	t_instance;
typedef struct s_list		t_list;
typedef struct s_font		t_font;

typedef struct s_global
{
	t_instance		*player;
	int				deathcount;
	int				inverted;
	int				state;
	int				time;
	int				total_time;

	int				steps;
}	t_global;

typedef struct s_footprint
{
	int				x;
	int				y;
	int				condition;
	t_sprite		*spr;
	t_list			*img_node;
}	t_footprint;

typedef struct s_obj_player
{
	int				inverted;
	int				attack;
	int				h_mv;
	int				v_mv;
	int				prev_x;
	int				prev_y;
	t_list			*route;
	t_list			*route_node;
	t_instance		*collision_zombie;
	t_instance		*collision_box;
	t_instance		*revive_zombie;
}	t_obj_player;

typedef struct s_obj_prop
{
	t_list			*route;
	t_list			*route_node;
}	t_obj_prop;

typedef union u_object
{
	t_obj_player	player;
	t_obj_prop		zombie;
	t_obj_prop		box;
}	t_object;

typedef struct s_asset
{
	t_canvas		*background_black;

	t_font			*font_default;

	t_sprite		*spr_player_idle_right;
	t_sprite		*spr_player_idle_left;
	t_sprite		*spr_player_move_right;
	t_sprite		*spr_player_move_left;
	t_sprite		*spr_player_attack_right;
	t_sprite		*spr_player_attack_left;
	t_sprite		*spr_player_die_right;
	t_sprite		*spr_player_die_left;

	t_sprite		*spr_zombie_idle_right_reverse;
	t_sprite		*spr_zombie_idle_left_reverse;
	t_sprite		*spr_zombie_die_right_reverse;
	t_sprite		*spr_zombie_die_left_reverse;

	t_sprite		*spr_empty;
	t_sprite		*spr_wall;
	t_sprite		*spr_box;
	t_sprite		*spr_box_break;
	t_sprite		*spr_gold;
	t_sprite		*spr_inverter;
	t_sprite		*spr_exit;

	t_scene			*scene_main;
	t_scene			*scene_tutorial;
	t_scene			*scene_mandatory;
	t_scene			*scene_play;
	t_scene			*scene_rank;
}	t_asset;

int			init_asset();
void		free_asset();

//background
int			init_background_black();

// font
int			init_font_default();

// sprite
int			init_spr_player();
int			init_spr_zombie();
int			init_spr_empty();
int			init_spr_wall();
int			init_spr_box();
int			init_spr_gold();
int			init_spr_inverter();
int			init_spr_exit();

// object
t_instance	*create_player_instance(int x, int y, int inverted);
void		obj_player_step(t_instance *this);
void		obj_player_draw(t_instance *this);

t_instance	*create_zombie_instance(int x, int y);
void		obj_zombie_step(t_instance *this);
void		obj_zombie_draw(t_instance *this);

t_instance	*create_wall_instance(int x, int y);
void		obj_wall_draw(t_instance *this);

t_instance	*create_box_instance(int x, int y);
void		obj_box_step(t_instance *this);
void		obj_box_draw(t_instance *this);

//script
void		scr_save_footprint(t_instance *this, t_list *route);
void		scr_load_footprint(t_instance *this, t_list **route_node, int inverted);
void		scr_animation(t_instance *this);
t_list		*scr_get_route(t_instance *id, int type);
t_list		**scr_get_route_node(t_instance *id, int type);

// scene
int			init_scene_play();
void		scene_play_start();
void		scene_play_controller();
void		scene_play_end();

#endif
