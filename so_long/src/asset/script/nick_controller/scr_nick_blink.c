/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_nick_blink.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:45:41 by su                #+#    #+#             */
/*   Updated: 2021/08/10 18:59:27 by su               ###   ########.fr       */
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
