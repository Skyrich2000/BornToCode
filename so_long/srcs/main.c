#include "engine.h"
#include "asset.h"

int main()
{
	init_game();
	init_asset();

	t_instance	*player;
	player = create_player_instance(50, 50);
	printf("done!\n", player);

	start_game();

	delete_sprite(g()->spr_player_idle);
	delete_sprite(g()->spr_player_move_right);
	return (0);
}
