/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:02 by ycha              #+#    #+#             */
/*   Updated: 2021/08/10 19:48:43 by su               ###   ########.fr       */
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
	DEBUG && printf("scene start\n");
	if (g()->scene->start)
		g()->scene->start();
	DEBUG && printf("scene start done\n");
}

void	scene_end(void)
{
	DEBUG && printf("scene end\n");
	if (g()->scene->end)
		g()->scene->end();
	DEBUG && printf("scene end done\n");
}

void	scene_restart(void)
{
	if (g()->scene->end)
		g()->scene->end();
	if (g()->scene->start)
		g()->scene->start();
}

void	scene_change(t_scene *scene)
{
	if (g()->scene->end)
		g()->scene->end();
	g()->scene = scene;
	if (g()->scene->start)
		g()->scene->start();
}
