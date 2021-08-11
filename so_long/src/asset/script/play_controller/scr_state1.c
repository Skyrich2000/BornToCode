/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_state1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:24:04 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:24:05 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_state_ready(void)
{
	g()->global.delay += 1;
	if (g()->global.delay > 60 * 2)
	{
		g()->global.state = S_STRAIGHT;
		g()->global.player->signal = 0;
	}
}

void	scr_state_straight(void)
{
	g()->global.time += 1;
	if (g()->global.time > 4200)
		scr_player_die(TXT_TIME_OVER, g()->global.player);
	if (g()->global.invert_signal == SIG_ACTIVE)
	{
		g()->global.state = S_INVERT;
		g()->global.max_time = g()->global.time;
		g()->global.invert_signal = SIG_NORMAL;
		scr_avatarize(BOX_RED);
		scr_avatarize(GOLD_RED);
	}
}

void	scr_state_inverted(void)
{
	t_instance	*dead_zombie;

	g()->global.time -= 1;
	if (g()->global.time < -4200)
		scr_player_die(TXT_TIME_OVER, g()->global.player);
	if (g()->global.invert_signal == SIG_ACTIVE)
	{
		g()->global.state = S_RESTRAIGHT;
		g()->global.invert_signal = SIG_NORMAL;
		scr_avatarize(ZOMBIE_BLUE);
		dead_zombie = scr_find_dead_zombie();
		if (dead_zombie)
			scr_player_die(TXT_TENET_ERROR, dead_zombie);
	}
}

void	scr_state_restraight(void)
{
	t_list		*node;
	t_instance	*ins;

	g()->global.time += 1;
	if (g()->global.time == g()->global.max_time)
	{
		node = g()->instances[PLAYER]->next;
		while (node)
		{
			ins = node->data;
			node = node->next;
			if (ins != g()->global.player)
				destroy_instance(ins);
		}
	}
	if (g()->global.time > g()->global.max_time && g()->global.player == 0)
	{
		g()->global.state = S_CLEAR;
		g()->global.delay = 0;
	}
}
