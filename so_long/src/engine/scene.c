/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:28:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:28:36 by ycha             ###   ########.fr       */
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
