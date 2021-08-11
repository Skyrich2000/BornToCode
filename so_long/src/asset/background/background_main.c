/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:07:18 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	init_background_main(void)
{
	g()->asset.background_main = \
			add_background("./res/png/background/background_main_0.png", 0, 0);
	return (OK);
}
