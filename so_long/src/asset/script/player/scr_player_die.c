/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_player_die.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:36:06 by su                #+#    #+#             */
/*   Updated: 2021/08/10 17:00:38 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_player_die(int text, t_instance *focus)
{
	t_instance	*ins;
	t_list		*node;

	if (g()->global.state == S_GAMEOVER)
		return ;
	g()->global.deathcount++;
	g()->global.delay = 0;
	g()->global.state = S_GAMEOVER;
	g()->global.text = text;
	if (focus)
	{
		g()->global.view_xview_aim = focus->x - g()->view.view_wview / 2;
		g()->global.view_yview_aim = focus->y - g()->view.view_hview / 2;
	}
	node = g()->instances[PLAYER]->next;
	while (node)
	{
		ins = node->data;
		ins->signal = 0;
		ins->condition = C_DEING;
		node = node->next;
	}
	node = g()->instances[PLAYER]->next;
	while (g()->instances[DUMMY]->next)
		destroy_instance(g()->instances[DUMMY]->next->data);
}
