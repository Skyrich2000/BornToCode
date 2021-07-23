#include "engine.h"

t_scene		*add_scene(t_canvas *background, void (*start)(void), void (*controller)(void), void (*ui)(void), void (*end)(void))
{
	t_scene *new;

	new = (t_scene *)malloc(sizeof(t_scene));
	if (!new)
		return (ERROR);
	new->background = background;
	new->start = start;
	new->controller = controller;
	new->ui = ui;
	new->end = end;
	return (new);
}

void		scene_start()
{
	if (DEBUG)
		printf("scene start\n");
	g()->scene->start();
	if (DEBUG)
		printf("scene start done\n");
}

void		scene_end()
{
	if (DEBUG)
		printf("scene end\n");
	g()->scene->end();
	if (DEBUG)
		printf("scene end done\n");
}

void		scene_restart()
{
	g()->scene->end();
	g()->scene->start();
}
