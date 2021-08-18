/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_nick_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:23:40 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:23:42 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

void	scr_nick_keycheck(char *ascii, char prev[50], char prev_backspace)
{
	int	i;

	i = -1;
	if (keyboard_check(KEY_ENTER) && g()->global.nick_index)
	{
		g()->global.nick[g()->global.nick_index] = '\0';
		scene_change(g()->asset.scene_play);
		return ;
	}
	if (keyboard_check(KEY_BACKSPACE) && !prev_backspace)
	{
		if (g()->global.nick_index > 0)
		{
			if (g()->global.nick[g()->global.nick_index] == '_')
				g()->global.nick[g()->global.nick_index] = ' ';
			g()->global.nick[--g()->global.nick_index] = ' ';
		}
		return ;
	}
	while (++i < 50)
	{
		if (keyboard_check(i) && !prev[i] && ascii[i] != '\0' && \
				g()->global.nick_index < NICK_SIZE)
			g()->global.nick[g()->global.nick_index++] = ascii[i];
	}
}

void	scr_nick_keysave(char prev[50], char *prev_backspace)
{
	int	i;

	i = -1;
	while (++i < 50)
		prev[i] = keyboard_check(i);
	*prev_backspace = keyboard_check(KEY_BACKSPACE);
}
