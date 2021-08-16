/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_rank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:07:48 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

int	init_background_rank(void)
{
	g()->asset.background_rank = add_background("./res/png/empty_0.png", 0, 0);
	return (OK);
}
