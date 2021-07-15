#include "engine.h"

t_instance  *create_instance(t_sprite *spr, int data[3], void (*step)(t_instance *this), void (*draw)(t_instance *this))
{
	t_instance *new;

	new = (t_instance *)malloc(sizeof(t_instance));
	if (!new || !push_list(g()->instances, new))
		return (ERROR);
    new->type = data[0];
	new->spr = spr;
	new->img_node = new->spr->imgs->next;
	new->img_speed = spr->img_speed;
	new->x = data[1];
	new->y = data[2];
	new->step = step;
	new->draw = draw;
    return (new);
}