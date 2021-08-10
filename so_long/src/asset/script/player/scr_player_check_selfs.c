/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_check_selfs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:35:45 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:35:47 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
		{
			g()->global.view_xview_aim = this->x - g()->view.view_wview / 2;
			g()->global.view_yview_aim = this->y - g()->view.view_hview / 2;
			scr_player_die(TXT_MEET_MYSELF);
		}
	}
}
