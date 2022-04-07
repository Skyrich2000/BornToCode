/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:18:45 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:18:46 by echung           ###   ########.fr       */
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
