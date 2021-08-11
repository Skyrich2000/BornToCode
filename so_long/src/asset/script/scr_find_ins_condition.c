/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_find_ins_condition.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:16:37 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:16:39 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
	node = g()->instances[ZOMBIE_BLUE]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins->condition & C_ALIVE)
			alive_gold = ins;
	}
	return (alive_gold);
}
