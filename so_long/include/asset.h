/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/08/06 03:45:07 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_H
# define ASSET_H
# include "engine.h"

# define BUFFER_SIZE		1000

# define MAP_SIZE			11
# define NICK_SIZE			10

# define EXIT				0
# define WALL				1
# define WALL_INV			2
# define BOX_RED			3
# define BOX_BLUE			4
# define TRIGGER			5
# define WAIT				6
# define INVERTER			7
# define DUMMY				8
# define ZOMBIE_BLUE		9
# define PLAYER				10
# define WALL_UP			11
# define GOLD_RED			12
# define PLANE				13
# define OBJ_SIZE			14

# define C_DEAD				1
# define C_DEING			2
# define C_ALIVE			4
# define C_AVATAR			8

# define S_READY			-1
# define S_STRAIGHT			0
# define S_INVERT			1
# define S_RESTRAIGHT		2
# define S_CLEAR			3
# define S_GAMEOVER			4

# define SIG_MV_AUTO		1
# define SIG_MV_RIGHT		2
# define SIG_MV_LEFT		4
# define SIG_MV_UP			8
# define SIG_MV_DOWN		16
# define SIG_DIR_RIGHT		32
# define SIG_DIR_LEFT		64
# define SIG_BEFORE			128
# define SIG_ACTIVE			256
# define SIG_NORMAL			512
# define SIG_NO_INVERT		1024

# define TXT_GAME_OVER		1
# define TXT_TIME_OVER		2
# define TXT_HIT_BY_ZOMBIE	3
# define TXT_MEET_MYSELF	4
# define TXT_TENET_ERROR	5
# define TXT_WAIT			6

typedef struct s_canvas		t_canvas;
typedef struct s_scene		t_scene;
typedef struct s_sprite		t_sprite;
typedef struct s_instance	t_instance;
typedef struct s_list		t_list;
typedef struct s_font		t_font;
typedef struct s_background	t_background;

typedef struct s_global
{
	int				nick_index;
	char			nick[NICK_SIZE + 1];

	char			**rank_list;
	int				rank_list_y;

	int				steps;
	int				time;
	int				time_all_lv;
	int				delay;
	int				deathcount;
	int				max_time;
	int				state;
	int				text;
	int				inverted;
	int				invert_signal;
	int				gold_num;
	t_instance		*player;
	int				darkness;

	int				view_xview_aim;
	int				view_yview_aim;

	int				tutorial;
	int				map_index;
	int				map_width;
	int				map_height;
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
	t_list			*route;
	t_list			*route_node;
	t_instance		*reviving_zombie;
}	t_obj_player;

typedef struct s_obj_dummy
{
	int				inverted;
	int				time;
	int				alive_time;
}	t_obj_dummy;

typedef struct s_obj_zombie
{
	t_list			*route;
	t_list			*route_node;
	t_instance		*reviver;
}	t_obj_zombie;

typedef struct s_obj_inverter
{
	int				time;
	int				inverted;
	int				out_dir[20];
	t_instance		*triggers[20];
	t_instance		*waits[20];
	t_instance		*dummy;
}	t_obj_inverter;

typedef struct s_obj_trigger
{
	t_instance		*target;
	int				signal;
	int				inverted;
}				t_obj_trigger;

typedef struct s_obj_prop
{
	t_list			*route;
	t_list			*route_node;
}	t_obj_prop;

typedef union u_object
{
	t_obj_player	player;
	t_obj_zombie	zombie;
	t_obj_prop		box;
	t_obj_prop		gold;
	t_obj_inverter	inverter;
	t_obj_trigger	trigger;
	t_obj_dummy		dummy;
}	t_object;

typedef struct s_asset
{
	t_sprite		*spr_player_blue_idle_right;
	t_sprite		*spr_player_blue_idle_left;
	t_sprite		*spr_player_blue_move_right;
	t_sprite		*spr_player_blue_move_left;
	t_sprite		*spr_player_blue_move_right_reverse;
	t_sprite		*spr_player_blue_move_left_reverse;
	t_sprite		*spr_player_blue_attack_right;
	t_sprite		*spr_player_blue_attack_left;
	t_sprite		*spr_player_blue_die_right;
	t_sprite		*spr_player_blue_die_left;

	t_sprite		*spr_player_red_idle_right;
	t_sprite		*spr_player_red_idle_left;
	t_sprite		*spr_player_red_move_right;
	t_sprite		*spr_player_red_move_left;
	t_sprite		*spr_player_red_move_right_reverse;
	t_sprite		*spr_player_red_move_left_reverse;
	t_sprite		*spr_player_red_attack_right;
	t_sprite		*spr_player_red_attack_left;
	t_sprite		*spr_player_red_die_right;
	t_sprite		*spr_player_red_die_left;

	t_sprite		*spr_zombie_blue_idle_right_reverse;
	t_sprite		*spr_zombie_blue_idle_left_reverse;
	t_sprite		*spr_zombie_blue_die_right_reverse;
	t_sprite		*spr_zombie_blue_die_left_reverse;

	t_sprite		*spr_light;
	t_sprite		*spr_light_5;

	t_sprite		*spr_empty;
	t_sprite		*spr_wall;
	t_sprite		*spr_wall_up;

	t_sprite		*spr_box_red;
	t_sprite		*spr_box_blue;
	t_sprite		*spr_box_red_break;

	t_sprite		*spr_gold_red;
	t_sprite		*spr_gold_red_break;

	t_sprite		*spr_inverter_idle;
	t_sprite		*spr_inverter_red;
	t_sprite		*spr_inverter_blue;

	t_sprite		*spr_exit;
	t_sprite		*spr_plane;
	t_sprite		*spr_logo;

	t_sprite		*spr_ready;
	t_sprite		*spr_straight;
	t_sprite		*spr_invert;
	t_sprite		*spr_clear;
	t_sprite		*spr_gameover;

	t_scene			*scene_main;
	t_scene			*scene_nick;
	t_scene			*scene_play;
	t_scene			*scene_rank;

	t_font			*font_su;
	t_font			*font_fat_xsmall;
	t_font			*font_fat_small;
	t_font			*font_fat_big;

	t_background	*background_main;
	t_background	*background_nick;
	t_background	*background_rank;
	t_background	*background_map_0;
	t_background	*background_map_1;
	t_background	*background_map_2;

	void			(*maps[MAP_SIZE])(int *w, int *h);
}	t_asset;

/* ************************************************************************** */

// init asset
int			init_asset(void);
// init background
int			init_background_main(void);
int			init_background_nick(void);
int			init_background_rank(void);
int			init_background_map(void);
// init font
int			init_font_su(void);
int			init_font_fat(void);
// init sprite
int			init_spr_player_blue(void);
int			init_spr_player_red(void);
int			init_spr_zombie(void);
int			init_spr_empty(void);
int			init_spr_wall(void);
int			init_spr_light(void);
int			init_spr_box(void);
int			init_spr_gold(void);
int			init_spr_inverter(void);
int			init_spr_exit(void);
int			init_spr_plane(void);
int			init_spr_logo(void);
int			init_spr_state(void);
// init scene
int			init_scene_main(void);
int			init_scene_nick(void);
int			init_scene_play(void);
int			init_scene_rank(void);
// init map
int			init_map(void);

/* ************************************************************************** */

// object player
t_instance	*create_player_instance(int x, int y);
void		obj_player_step(t_instance *this);
void		obj_player_draw(t_instance *this);
// object zombie blue
t_instance	*create_zombie_blue_instance(int x, int y);
void		obj_zombie_blue_step(t_instance *this);
void		obj_zombie_blue_draw(t_instance *this);
// object box red, blue
t_instance	*create_box_red_instance(int x, int y);
t_instance	*create_box_blue_instance(int x, int y);
void		obj_box_red_step(t_instance *this);
void		obj_box_red_draw(t_instance *this);
// object gold red
t_instance	*create_gold_red_instance(int x, int y);
void		obj_gold_red_step(t_instance *this);
void		obj_gold_red_draw(t_instance *this);
// object inverter
t_instance	*create_inverter_instance(int x, int y, int inverted, int dir[5]);
void		obj_inverter_step(t_instance *this);
void		obj_inverter_draw(t_instance *this);
// object dummy
t_instance	*create_dummy_instance(int x, int y, int inverted, int time);
void		obj_dummy_step(t_instance *this);
void		obj_dummy_draw(t_instance *this);
// object plane
t_instance	*create_plane_instance(void);
void		obj_plane_step(t_instance *this);
// object wall, wall up, wall invisible
t_instance	*create_wall_instance(int x, int y);
t_instance	*create_wall_up_instance(int x, int y);
t_instance	*create_wall_inv_instance(int x, int y);
// object trigger
t_instance	*create_trigger_instance(int pos[2], int inverted, \
											t_instance *target, int sigal);
// object exit
t_instance	*create_exit_instance(int x, int y);
// object wait
t_instance	*create_wait_instance(int x, int y);

/* ************************************************************************** */

// scripts to save or load footprint
void		scr_save_footprint(t_instance *this, t_list *route);
void		scr_load_footprint(t_instance *this, t_list **route, int inverted);
// script to animation
void		scr_animation(t_instance *this);
// scripts to get route or route node
t_list		*scr_get_route(t_instance *id, int type);
t_list		**scr_get_route_node(t_instance *id, int type);
// script for trigger
void		scr_trigger(t_instance *trigger);
// script to move dummy
void		scr_dummy_move_auto(t_instance *this);
// script for player to attack
void		scr_player_attack(t_instance *this);
// script to check if player is nearby
void		scr_player_check_selfs(t_instance *this);
// scripts for check player collision
int			scr_player_collision_box(t_instance *this);
void		scr_player_collision_gold(t_instance *this);
void		scr_player_collision_inverter(t_instance *this);
void		scr_player_collision_trigger(t_instance *this);
void		scr_player_collision_zombie(t_instance *this);
void		scr_player_collision_exit(t_instance *this);
void		scr_player_collision_wait(t_instance *this);
// script to get player sprite pointer
t_sprite	*scr_player_get_spr(int type, int inverted, int dir);
// scripts to move player
void		scr_player_move_auto(t_instance *this);
void		scr_player_move(t_instance *this);
// script kill all players when player dead
void		scr_player_die(int text);
// scirpt to mvoe zombie
void		scr_zombie_move(t_instance *this);
// script to make instance avatar
void		scr_avatarize(int type);
// scripts for manage global state of game
void		scr_state_ready(void);
void		scr_state_straight(void);
void		scr_state_inverted(void);
void		scr_state_restraight(void);
void		scr_state_clear(void);
void		scr_state_gameover(void);
// script to calculate signal
int			scr_reverse_mv_signal(int signal);
int			scr_convert_mv_signal(int signal);
// scripts to manage triggers from inverter
void		scr_inverter_create_trigger(t_instance *this);
void		scr_inverter_destroy_trigger(t_instance *this, int exclusive_sig);
// scripts to manage wait objects and invisible wall objects
void		scr_inverter_create_wait(t_instance *this);
void		scr_inverter_destroy_wait(t_instance *this);
// script when inverter received signal
void		scr_inverter_before(t_instance *this);
void		scr_inverter_active(t_instance *this);
// script for build map from char** return width and height of map
void		scr_build_map(char **map, int *width, int *height);
// script for save rank
void		scr_save_rank(char *name, int time, int deathcount);

/* ************************************************************************** */

// scene main
void		scene_main_start(void);
void		scene_main_controller(void);
void		scene_main_ui(void);
void		scene_main_end(void);
// scene nickname
void		scene_nick_start(void);
void		scene_nick_controller(void);
void		scene_nick_ui(void);
void		scene_nick_end(void);
// scene play
void		scene_play_start(void);
void		scene_play_controller(void);
void		scene_play_ui(void);
void		scene_play_end(void);
// scene rank
void		scene_rank_start(void);
void		scene_rank_controller(void);
void		scene_rank_ui(void);
void		scene_rank_end(void);

/* ************************************************************************** */

void		map_0_0(int *width, int *height);
void		map_0_1(int *width, int *height);
void		map_0_2(int *width, int *height);
void		map_0_3(int *width, int *height);
void		map_0_4(int *width, int *height);
void		map_0_5(int *width, int *height);
void		map_1(int *width, int *height);
void		map_2(int *width, int *height);
void		map_3(int *width, int *height);
void		map_4(int *width, int *height);
void		map_5(int *width, int *height);

#endif
