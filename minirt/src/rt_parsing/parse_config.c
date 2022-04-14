/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:34:39 by echung            #+#    #+#             */
/*   Updated: 2022/03/06 23:34:42 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_r(char **line)
{
	if ((m()->scr.wid && m()->scr.hei)
		|| ft_arrsize(line) != 3
		|| !ft_atod(&m()->scr.wid, line[1])
		|| !ft_atod(&m()->scr.hei, line[2]))
		return (ERROR);
	return (OK);
}

int	parse_a(char **line)
{
	t_minirt	*g;

	g = m();
	if (m()->light->origin.x == 1
		|| ft_arrsize(line) != 3
		|| !ft_atod(&m()->light->origin.x, "1")
		|| !ft_atod(&m()->light->ratio, line[1])
		|| !parse_split(&m()->light->color, line[2]))
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
	if (!add_light(m()->light, c, vec_divn(color, 255), ratio))
		return (ERROR);
	return (OK);
}
