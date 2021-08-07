#include "engine.h"

t_list	*scr_get_route(t_instance *id, int type)
{
	if (type == PLAYER)
		return (id->obj.player.route);
	else if (type == ZOMBIE_BLUE)
		return (id->obj.zombie.route);
	else
		return (id->obj.box.route);
}

t_list	**scr_get_route_node(t_instance *id, int type)
{
	if (type == PLAYER)
		return (&id->obj.player.route_node);
	else if (type == ZOMBIE_BLUE)
		return (&id->obj.zombie.route_node);
	else
		return (&id->obj.box.route_node);
}
