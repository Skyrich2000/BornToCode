/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 15:09:32 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_background_nick(void)
{
	g()->asset.background_nick = \
			add_background("./res/png/background/background_main_0.png", 0, 0);
	return (OK);
}
