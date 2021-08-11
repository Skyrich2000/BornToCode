/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_nick_blink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:23:34 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:23:35 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"
#include "asset.h"

void	scr_nick_blink(void)
{
	if (g()->global.time > 20 && g()->global.nick_index < NICK_SIZE)
	{
		g()->global.time = 0;
		if (g()->global.nick[g()->global.nick_index] == '_')
			g()->global.nick[g()->global.nick_index] = ' ';
		else
			g()->global.nick[g()->global.nick_index] = '_';
	}
}
