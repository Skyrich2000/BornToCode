#include "engine.h"

void	scr_save_footprint(t_instance *this, t_list *route)
{
	t_footprint *footprint;

	footprint = malloc(sizeof(t_footprint));
	footprint->x = this->x;
	footprint->y = this->y;
	footprint->spr = this->spr;
	footprint->img_node = this->img_node;
	footprint->condition = this->condition | C_AVATAR;
	push_list(route, footprint);
}

void	scr_load_footprint(t_instance *this, t_list **route_node, int inverted)
{
	t_footprint *fp;
	t_list *prev_node;

	prev_node = *route_node;
	if (g()->global.inverted == inverted)
		*route_node = (*route_node)->prev;
	else
		*route_node = (*route_node)->next;
	if (!*route_node)
		*route_node = prev_node;
	fp = (*route_node)->data;
	if (fp)
	{
		this->x = fp->x;
		this->y = fp->y;
		this->spr = fp->spr;
		this->img_node = fp->img_node;
		this->condition = fp->condition;
	}
}
