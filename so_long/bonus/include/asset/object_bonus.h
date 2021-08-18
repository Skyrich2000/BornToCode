/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:05:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:06:46 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_BONUS_H
# define OBJECT_BONUS_H
# include "engine/engine_bonus.h"

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
# define TXT_GOLD_LEFT		6
# define TXT_WAIT			7

typedef struct s_sprite		t_sprite;
typedef struct s_instance	t_instance;

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

#endif
