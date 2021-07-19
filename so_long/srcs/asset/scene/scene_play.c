#include "engine.h"

int			init_scene_play()
{
	t_scene	*new;

	new = add_scene(g()->asset.background_black, scene_play_start, scene_play_controller, scene_play_end);
	if (!new)
		return (ERROR);
	g()->asset.scene_play = new;
	return (OK);
}

void		scene_play_start()
{
	g()->global.deathcount = 0;
	g()->global.inverted = 0;
	g()->global.status = 0;
	g()->global.time = 0;
	g()->global.total_time = 0;
	create_player_instance(50, 50);
	create_zombie_instance(250, 210);
}

void		scene_play_controller()
{
	if (g()->global.status == 0) // straight
	{
		g()->global.time += 1;
		if (g()->global.time > 60 * 60)
			scene_restart();
		if (keyboard_check(KEY_I))
		{
			printf("inversion start\n");
			g()->global.inverted = 1;
			g()->global.status = 1;
			g()->global.avatar = create_avatar_instance(g()->global.straight, 1);
		}
	}
	else if (g()->global.status == 1) // inverted
	{
		printf("replay start\n");
		destroy_instance(g()->instances[PLAYER]->next->data);
		create_avatar_instance(g()->global.straight, 0);
		create_avatar_instance(g()->global.reverse, 1);
	}
	else if (g()->global.status == 2) // re straight
	{
		printf("scene restart\n");
		scene_restart();
	}
	else if (g()->global.status == 3) // end
	{

	}
}

void		scene_play_end()
{
	scene_end();
	free_list(g()->global.straight, sl_free);
	free_list(g()->global.reverse, sl_free);
}

