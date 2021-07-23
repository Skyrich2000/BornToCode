/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/07/24 05:22:57 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSET_H
# define ASSET_H
# include "engine.h"

# define BOX				0
# define EXIT				1
# define WALL				2
# define TRIGGER			3
# define INVERTER			4
# define DUMMY				5
# define ZOMBIE				6
# define PLAYER				7
# define GOLD				8
# define OBJ_SIZE			9

# define C_DEAD				1
# define C_DEING			2
# define C_ALIVE			4
# define C_AVATAR			8

# define S_READY			-1
# define S_STRAIGHT			0
# define S_INVERT			1
# define S_RESTRAIGHT		2
# define S_GAMEOVER			3
# define S_CLEAR			4

# define SIG_AUTO			1
# define SIG_MV_RIGHT		2
# define SIG_MV_LEFT		4
# define SIG_MV_UP			8
# define SIG_MV_DOWN		16
# define SIG_DIR_RIGHT		32
# define SIG_DIR_LEFT		64
# define SIG_BEFORE			128
# define SIG_ACTIVE			256

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
	int				inverted;
	int				out_dir[20];
	t_instance		*dummy;
}	t_obj_inverter;

typedef struct s_obj_trigger
{
	t_instance		*target;
	int				signal;
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

// 포인터 위치 절대 바꾸지 말 것 !!!!
typedef struct s_asset
{
	t_canvas		*background_black;

	t_font			*font_default;

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

	t_sprite		*spr_zombie_idle_right_reverse;
	t_sprite		*spr_zombie_idle_left_reverse;
	t_sprite		*spr_zombie_die_right_reverse;
	t_sprite		*spr_zombie_die_left_reverse;

	t_sprite		*spr_light;
	t_sprite		*spr_empty;
	t_sprite		*spr_wall;
	t_sprite		*spr_box;
	t_sprite		*spr_box_break;
	t_sprite		*spr_gold;
	t_sprite		*spr_gold_break;
	t_sprite		*spr_inverter_idle;
	t_sprite		*spr_inverter_red;
	t_sprite		*spr_inverter_blue;
	t_sprite		*spr_exit_open;
	t_sprite		*spr_exit_close;

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
int			init_spr_player_blue();
int			init_spr_player_red();
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
t_instance	*create_gold_instance(int x, int y);
void		obj_gold_step(t_instance *this);
void		obj_gold_draw(t_instance *this);
t_instance	*create_inverter_instance(int x, int y, int inverted, int from_dir[5]);
void		obj_inverter_step(t_instance *this);
void		obj_inverter_draw(t_instance *this);
t_instance	*create_trigger_instance(int pos[2], t_sprite *mask, t_instance *target, int signal);
t_instance	*create_dummy_instance(int x, int y, int inverted, int time);
void		obj_dummy_step(t_instance *this);
void		obj_dummy_draw(t_instance *this);

//script
void		scr_save_footprint(t_instance *this, t_list *route);
void		scr_load_footprint(t_instance *this, t_list **route_node, int inverted);
void		scr_animation(t_instance *this);
t_list		*scr_get_route(t_instance *id, int type);
t_list		**scr_get_route_node(t_instance *id, int type);
void		scr_trigger(t_instance *trigger);
void		scr_dummy_move_auto(t_instance *this);
void		scr_player_attack(t_instance *this);
void		scr_player_check_selfs(t_instance *this);
int			scr_player_collision_box(t_instance *this);
void		scr_player_collision_gold(t_instance *this);
void		scr_player_collision_inverter(t_instance *this);
void		scr_player_collision_trigger(t_instance *this);
void		scr_player_collision_zombie(t_instance *this);
t_sprite	*scr_player_get_spr(int type, int inverted, int dir);
void		scr_player_move_auto(t_instance *this);
void		scr_player_move(t_instance *this);
void		scr_player_die();
void		scr_zombie_move(t_instance *this);
void		scr_avatarize(int type);
void		scr_state_ready();
void		scr_state_straight();
void		scr_state_inverted();
void		scr_state_restraight();
void		scr_state_clear();
void		scr_state_gameover();
int			scr_reverse_mv_signal(int signal);
int			scr_convert_mv_signal(int signal);
void		scr_inverter_trigger(t_instance *this);
void		scr_inverter_before(t_instance *this);
void		scr_inverter_active(t_instance *this);
// scene
int			init_scene_play();
void		scene_play_start();
void		scene_play_controller();
void		scene_play_ui();
void		scene_play_end();

#endif
