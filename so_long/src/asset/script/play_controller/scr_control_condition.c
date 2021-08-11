/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_control_condition.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:23:54 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:23:55 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_avatarize(int type)
{
	t_instance	*ins;
	t_list		*node;
	t_list		**route_node;

	node = g()->instances[type]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins->condition & C_AVATAR)
			continue ;
		ins->condition |= C_AVATAR;
		route_node = scr_get_route_node(ins, type);
		*route_node = scr_get_route(ins, type)->next;
	}
}

t_instance	*scr_find_dead_zombie(void)
{
	t_instance	*dead_zombie;
	t_instance	*ins;
	t_list		*node;

	dead_zombie = 0;
	node = g()->instances[ZOMBIE_BLUE]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins->condition & C_DEAD)
		{
			ins->condition = C_ALIVE;
			dead_zombie = ins;
		}
	}
	return (dead_zombie);
}

t_instance	*scr_find_alive_gold(void)
{
	t_instance	*alive_gold;
	t_instance	*ins;
	t_list		*node;

	alive_gold = 0;
	node = g()->instances[GOLD_RED]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins->condition & C_ALIVE)
			alive_gold = ins;
	}
	return (alive_gold);
}
