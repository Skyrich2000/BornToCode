#include "engine.h"
#include "asset.h"

void	init_asset()
{
	t_game *game;

	game = g();
	game->asset.spr_player_idle = add_sprite(0, 0, 10);
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_8.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_7.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_6.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_5.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_4.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_3.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_2.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_1.xpm");
	add_sprite_subimage(game->asset.spr_player_idle, "./res/xpm/player_0.xpm");

	game->asset.spr_player_move_right = add_sprite(0, 0, 5);
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_14.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_13.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_12.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_11.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_10.xpm");
	add_sprite_subimage(game->asset.spr_player_move_right, "./res/xpm/player_9.xpm");

	game->asset.spr_player_move_left = add_sprite(0, 0, 5);
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm/player_14.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm/player_13.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm/player_12.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm/player_11.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm/player_10.xpm");
	add_sprite_subimage(game->asset.spr_player_move_left, "./res/xpm/player_9.xpm");
}
