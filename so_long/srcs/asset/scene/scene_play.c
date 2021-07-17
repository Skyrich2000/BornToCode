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
	g()->global.straight = create_list();
	g()->global.reverse = create_list();
	g()->global.deathcount = 0;
	g()->global.inverted = 0;
	g()->global.status = 0;
	create_player_instance(50, 50);
	create_zombie_instance(250, 210);
}

void		scene_play_controller()
{
	if (g()->global.status == 0)
	{
		g()->global.steps += 1;
		if (g()->global.steps > 60 * 60)
			scene_restart();
		if (g()->global.inverted == 0 && keyboard_check(KEY_I))
		{
			printf("inversion start\n");
			g()->global.inverted = 1;
			create_avatar_instance(g()->global.straight, 1);
		}
	}
	else if (g()->global.status == 1)
	{
		printf("replay start\n");
		destroy_instance(g()->instances[PLAYER]->next->data);
		create_avatar_instance(g()->global.straight, 0);
		create_avatar_instance(g()->global.reverse, 1);
		g()->global.status = 2;
	}
	else if (g()->global.status == 3)
	{
		printf("scene restart\n");
		scene_restart();
	}
}

void		scene_play_end()
{
	scene_end();
	g()->global.steps = 0;
	free_list(g()->global.straight, sl_free);
	free_list(g()->global.reverse, sl_free);
}

