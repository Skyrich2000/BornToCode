/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_check_selfs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:24:54 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:24:55 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

void	scr_player_check_selfs(t_instance *this)
{
	t_list		*node;
	t_instance	*ins;

	node = g()->instances[PLAYER]->next;
	while (node)
	{
		ins = node->data;
		node = node->next;
		if (ins == this)
			continue ;
		if (point_distance(ins->x, ins->y, this->x, this->y) < 32 * 32)
			scr_player_die(TXT_MEET_MYSELF, this);
	}
}
