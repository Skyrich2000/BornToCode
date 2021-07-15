#ifndef ASSET_H
# define ASSET_H
# include "engine.h"

#define PLAYER 0
#define ZOMBIE 1
#define WALL 2
#define KEY 3
#define EXIT 4

# define KEY_A				0
# define KEY_S				1
# define KEY_D				2


typedef struct		s_sprite t_sprite;
typedef struct		s_instance t_instance;

typedef struct		s_obj_player
{
	int				hp;
	int				mv;
}					t_obj_player;

typedef struct		s_obj_zombie
{
	int				hp;
}					t_obj_zombie;

typedef union		u_object
{
	t_obj_player	player;
	t_obj_zombie	zombie;
}					t_object;

typedef struct		s_asset
{
	t_sprite		*spr_player_idle;
	t_sprite		*spr_player_move_right;
	t_sprite		*spr_player_move_left;
	t_sprite		*spr_zombie;
	t_sprite		*spr_wall;
	t_sprite		*spr_key;
	t_sprite		*spr_exit;
}					t_asset;

void		init_asset();

t_instance	*create_player_instance(int x, int y);
void		obj_player_step(t_instance *this);
void		obj_player_draw(t_instance *this);

t_instance	*create_zombie_instance(int x, int y);
void		obj_zombie_step(t_instance *this);
void		obj_zombie_draw(t_instance *this);

#endif
