#include "engine.h"

t_scene		*add_scene(t_canvas *background, void (*start)(void), void (*end)(void))
{
	t_scene *new;

	new = (t_scene *)malloc(sizeof(t_scene));
	if (!new)
		return (ERROR);
	new->background = background;
	new->start = start;
	new->end = end;
	return (new);
}

void		scene_end()
{
	int i;

	i = -1;
	while (++i < OBJ_SIZE)
	{
		free_list(g()->instances[i], sl_free);
	}
}
