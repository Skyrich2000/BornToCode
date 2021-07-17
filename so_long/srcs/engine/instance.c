/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:08 by ycha              #+#    #+#             */
/*   Updated: 2021/07/17 03:05:53 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_instance  *create_instance(t_sprite *spr, int data[3], void (*step)(t_instance *this), void (*draw)(t_instance *this))
{
	t_list		*node;
	t_instance	*new;

	new = (t_instance *)malloc(sizeof(t_instance));
	if (!new)
		return (ERROR);
	node = push_list(g()->instances[data[0]], new);
	if (!node)
		return (ERROR);
	new->node = node;
	new->type = data[0];
	new->spr = spr;
	new->img_node = new->spr->imgs->next;
	new->img_speed = spr->img_speed;
	new->x = data[1];
	new->y = data[2];
	new->dir = 1;
	new->step = step;
	new->draw = draw;
	new->draw_time = 0;
    return (new);
}

void		destroy_instance(t_instance *id)
{
	pop_list(id->node);
	free(id);
}
