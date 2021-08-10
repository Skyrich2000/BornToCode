/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_alive_zombie.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:45:41 by su                #+#    #+#             */
/*   Updated: 2021/08/10 20:26:28 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance	*scr_alive_zombie(void)
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
