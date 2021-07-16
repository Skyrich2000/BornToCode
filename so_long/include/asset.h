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

# define PLAYER 0
# define ZOMBIE 1
# define WALL 2
# define KEY 3
# define EXIT 4
# define ROUND 5
# define OBJ_SIZE 6

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_W				13
# define KEY_SPACEBAR		49

# define KEY_LEFT			123
# define KEY_DOWN			125
# define KEY_RIGHT			124
# define KEY_UP				126

typedef struct		s_sprite t_sprite;
typedef struct		s_instance t_instance;
typedef struct		s_list t_list;

typedef struct		s_footprint
{
	int				x;
	int				y;
	int				dir;
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

typedef struct		s_obj_round
{
	t_list			*straight;
	t_list			*reverse;
	int				steps;
	int				deathcount;
	int				inverted;

}					t_obj_round;

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
	t_obj_round		round;
	t_obj_avatar	avatar;
}					t_object;

typedef struct		s_asset
{
	t_sprite		*spr_player_idle_right;
	t_sprite		*spr_player_idle_left;
	t_sprite		*spr_player_move_right;
	t_sprite		*spr_player_move_left;
	t_sprite		*spr_player_attack_right;
	t_sprite		*spr_player_attack_left;
	t_sprite		*spr_player_die_right;
	t_sprite		*spr_player_die_left;

	t_sprite		*spr_zombie_move_right;
	t_sprite		*spr_zombie_move_left;
	t_sprite		*spr_zombie_die_right;
	t_sprite		*spr_zombie_die_left;
	t_sprite		*spr_wall;
	t_sprite		*spr_key;
	t_sprite		*spr_exit;
}					t_asset;

void		init_asset();

t_instance	*create_player_instance(int x, int y);
void		obj_player_step(t_instance *this);
void		obj_player_draw(t_instance *this);

t_instance	*create_zombie_instance(int x, int y);
void		obj_zombie_draw(t_instance *this);

t_instance	*create_avatar_instance(t_list *route, int dir);
void		obj_avatar_step(t_instance *this);
void		obj_avatar_draw(t_instance *this);

t_instance	*create_round_instance();

#endif
