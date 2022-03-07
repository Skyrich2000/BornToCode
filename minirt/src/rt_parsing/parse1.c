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

int	parse_a(char **line)
{
	if (m()->light->origin.x == 1
		|| ft_arrsize(line) != 3
		|| !ft_atod(&m()->light->origin.x, "1")
		|| !ft_atod(&m()->light->ratio, line[1])
		|| !parse_split(&m()->light->color, line[2]))
		return (ERROR);
	m()->light->color = vec_divn(m()->light->color, 255);
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
	if (!add_camera(c, dir, fov))
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

int	parse_pl(char **line)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;

	if (ft_arrsize(line) != 4
		|| !parse_split(&c, line[1])
		|| !parse_split(&n, line[2])
		|| !parse_split(&color, line[3]))
		return (ERROR);
	if (!add_world(m()->wrd,
			create_plane(c, n),
			hit_plane,
			create_metal(color, (double)rand() / (double)RAND_MAX)))
		return (ERROR);
	return (OK);
}

int	parse_cy(char **line)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;
	double	r;
	double	h;

	if (ft_arrsize(line) != 6
		|| !ft_atod(&r, line[3])
		|| !ft_atod(&h, line[4])
		|| !parse_split(&c, line[1])
		|| !parse_split(&n, line[2])
		|| !parse_split(&color, line[5]))
		return (ERROR);
	if (!add_world(m()->wrd,
			create_cylinder(c, n, r, h),
			hit_cylinder,
			create_metal(color, (double)rand() / (double)RAND_MAX)))
		return (ERROR);
	return (OK);
}
