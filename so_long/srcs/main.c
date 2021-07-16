#include "engine.h"
#include "asset.h"

int main()
{
	init_game();
	init_asset();

	create_player_instance(50, 50);
	create_zombie_instance(450, 150);
	create_zombie_instance(450, 100);
	create_zombie_instance(450, 50);
	create_zombie_instance(450, 75);
	printf("loading done!\n");

	start_game();

	delete_sprite(g()->asset.spr_player_idle_right);
	delete_sprite(g()->asset.spr_player_move_right);
	return (0);
}
