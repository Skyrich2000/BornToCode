/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_get_route.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:16:20 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:16:21 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

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
