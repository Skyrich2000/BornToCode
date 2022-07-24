/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:29:35 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:29:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	*init_light(void)
{
	t_light	*head;

	head = (t_light *)malloc(sizeof(t_light));
	if (!head)
		return (0);
	head->origin = vec(0, 0, 0);
	head->next = 0;
	return (head);
}

int	add_light(t_light *head, t_pnt origin, t_clr color, double ratio)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (ERROR);
	light->origin = origin;
	light->color = color;
	light->ratio = ratio;
	light->next = head->next;
	head->next = light;
	return (OK);
}
