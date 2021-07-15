#include "engine.h"
#include "asset.h"

void	init_asset()
{
	t_game *game;

	game = g();
	game->spr_player_idle = create_sprite();
	add_subimage(game->spr_player_idle, "./img/xpm/player_8.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_7.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_6.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_5.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_4.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_3.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_2.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_1.xpm");
	add_subimage(game->spr_player_idle, "./img/xpm/player_0.xpm");

	game->spr_player_move_right = create_sprite();
	add_subimage(game->spr_player_move_right, "./img/xpm/player_14.xpm");
	add_subimage(game->spr_player_move_right, "./img/xpm/player_13.xpm");
	add_subimage(game->spr_player_move_right, "./img/xpm/player_12.xpm");
	add_subimage(game->spr_player_move_right, "./img/xpm/player_11.xpm");
	add_subimage(game->spr_player_move_right, "./img/xpm/player_10.xpm");
	add_subimage(game->spr_player_move_right, "./img/xpm/player_9.xpm");

}
