/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:08 by ycha              #+#    #+#             */
/*   Updated: 2021/07/22 02:57:57 by ycha             ###   ########.fr       */
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
	new->spr = spr;
	new->img_node = new->spr->imgs->next;
	new->x = data[1];
	new->y = data[2];
	new->dir = 1;
	new->condition = 0;
	new->step = step;
	new->draw = draw;
	new->draw_time = 0;
    return (new);
}

int			point_distance(int x1, int y1, int x2, int y2)
{
	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int			place_meeting(t_instance *id, int x, int y, t_instance *other)
{
	t_box		box;
	t_box		box2;

	box.x1 = x - id->spr->offset_x + id->spr->mask.x1;
	box.y1 = y - id->spr->offset_y + id->spr->mask.y1;
	box.x2 = x - id->spr->offset_x + id->spr->mask.x2;
	box.y2 = y - id->spr->offset_y + id->spr->mask.y2;
	box2.x1 = other->x - other->spr->offset_x + other->spr->mask.x1;
	box2.y1 = other->y - other->spr->offset_y + other->spr->mask.y1;
	box2.x2 = other->x - other->spr->offset_x + other->spr->mask.x2;
	box2.y2 = other->y - other->spr->offset_y + other->spr->mask.y2;
	return (box.x2 >= box2.x1 && box2.x2 >= box.x1 && \
			box.y2 >= box2.y1 && box2.y2 >= box.y1);
}

t_instance	*place_meeting_type(t_instance *id, int x, int y, int type)
{
	t_instance	*ins;
	t_list		*node;

	node = g()->instances[type]->next;
	while (node)
	{
		ins = node->data;
		if (place_meeting(id, x, y, ins))
			return (ins);
		node = node->next;
	}
	return (ERROR);
}


void		destroy_all_instance()
{
	int i;

	i = -1;
	while (++i < OBJ_SIZE)
	{
		while (g()->instances[i]->next)
			destroy_instance(g()->instances[i]->next->data);
	}
}

void		destroy_instance(t_instance *id)
{
	pop_list(id->node);
	free(id);
}