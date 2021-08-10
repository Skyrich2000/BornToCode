/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:14:19 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:14:19 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_animation(t_instance *this)
{
	this->draw_time++;
	if (this->draw_time > this->spr->img_speed)
	{
		this->img_node = this->img_node->next;
		this->draw_time = 0;
	}
	if (!this->img_node)
		this->img_node = this->spr->imgs->next;
}
