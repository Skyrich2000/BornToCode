/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font_su.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:50 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:08:02 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"

int	init_font_su(void)
{
	g()->asset.font_su = add_font("./res/png/font/font_su/", 40);
	if (!g()->asset.font_su)
		return (ERROR);
	return (OK);
}
