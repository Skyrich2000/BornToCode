#include "engine.h"

t_scene		*add_scene(t_canvas *background, void (*start)(void), void (*controller)(void), void (*end)(void))
{
	t_scene *new;

	new = (t_scene *)malloc(sizeof(t_scene));
	if (!new)
		return (ERROR);
	new->background = background;
	new->start = start;
	new->controller = controller;
	new->end = end;
	return (new);
}

void		scene_end()
{
	int i;

	i = -1;
	while (++i < OBJ_SIZE)
	{
		while (g()->instances[i]->next)
			destroy_instance(g()->instances[i]->next->data);
	}
}

void		scene_restart()
{
	g()->scene->end();
	g()->scene->start();
}