/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:02 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 03:27:27 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_scene	*add_scene(t_background *background, void (*start)(void), \
		void (*controller)(void), void (*ui)(void), void (*end)(void))
{
	t_scene	*new;

	new = (t_scene *)malloc(sizeof(t_scene));
	if (!new)
		sl_exit(12);
	new->background = background;
	new->start = start;
	new->controller = controller;
	new->ui = ui;
	new->end = end;
	return (new);
}

void	scene_start(void)
{
	if (DEBUG)
		printf("scene start\n");
	g()->scene->start();
	if (DEBUG)
		printf("scene start done\n");
}

void	scene_end(void)
{
	if (DEBUG)
		printf("scene end\n");
	g()->scene->end();
	if (DEBUG)
		printf("scene end done\n");
}

void	scene_restart(void)
{
	g()->scene->end();
	g()->scene->start();
}

void	scene_change(t_scene *scene)
{
	g()->scene->end();
	g()->scene = scene;
	g()->scene->start();
}
