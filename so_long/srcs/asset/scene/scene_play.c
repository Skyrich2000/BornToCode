#include "engine.h"

int			init_scene_play()
{
	t_scene	*new;

	new = (t_scene *)malloc(sizeof(t_scene));
	if (!new)
		return (ERROR);
	new->background = g()->asset.background_black;
	new->start = scene_play_start;
	new->end = scene_play_end;
	g()->asset.scene_play = new;
	return (OK);
}

void		scene_play_start()
{
	g()->global.straight = create_list();
	g()->global.reverse = create_list();
	g()->global.deathcount = 0;
	g()->global.inverted = 0;
	create_player_instance(50, 50);
	create_zombie_instance(450, 150);
	create_zombie_instance(450, 100);
	create_zombie_instance(450, 50);
	create_zombie_instance(450, 75);
}

void		scene_play_end()
{
	scene_end();
	free_list(g()->global.straight, sl_free);
	free_list(g()->global.reverse, sl_free);
}

