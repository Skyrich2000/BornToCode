/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:34:39 by echung            #+#    #+#             */
/*   Updated: 2022/04/23 21:54:37 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_a(char **line)
{
	t_minirt	*g;

	g = m();
	if (ft_arrsize(line) != 3
		|| !ft_atod(&m()->light->ratio, line[1])
		|| !parse_split(&m()->light->color, line[2]))
		return (ERROR);
	if (m()->light->ratio < 0.0 || m()->light->ratio > 1.0)
		return (ERROR);
	if (m()->light->color.x < 0 || m()->light->color.x > 255)
		return (ERROR);
	if (m()->light->color.y < 0 || m()->light->color.y > 255)
		return (ERROR);
	if (m()->light->color.z < 0 || m()->light->color.z > 255)
		return (ERROR);
	g->light->color = vec_divn(g->light->color, 255);
	return (OK);
}

int	parse_c(char **line)
{
	t_vec	c;
	t_vec	dir;
	double	fov;

	if (ft_arrsize(line) != 4
		|| !ft_atod(&fov, line[3])
		|| !parse_split(&c, line[1])
		|| !parse_split(&dir, line[2]))
		return (ERROR);
	if (fov < 0 || fov > 180)
		return (ERROR);
	if (dir.x < -1 || dir.x > 1)
		return (ERROR);
	if (dir.y < -1 || dir.y > 1)
		return (ERROR);
	if (dir.z < -1 || dir.z > 1)
		return (ERROR);
	if (!add_camera(m()->cam, c, dir, fov))
		return (ERROR);
	return (OK);
}

int	parse_l(char **line)
{
	t_pnt	c;
	t_clr	color;
	double	ratio;

	if (ft_arrsize(line) != 4
		|| !ft_atod(&ratio, line[2])
		|| !parse_split(&c, line[1])
		|| !parse_split(&color, line[3]))
		return (ERROR);
	if (ratio < 0.0 || ratio > 1.0)
		return (ERROR);
	if (color.x < 0 || color.x > 255)
		return (ERROR);
	if (color.y < 0 || color.y > 255)
		return (ERROR);
	if (color.z < 0 || color.z > 255)
		return (ERROR);
	if (!add_light(m()->light, c, vec_divn(color, 255), ratio))
		return (ERROR);
	return (OK);
}
