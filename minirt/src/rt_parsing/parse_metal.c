/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:34:48 by echung            #+#    #+#             */
/*   Updated: 2022/03/06 23:34:50 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define R 0
#define H 1

int	parse_sp_metal(char **line)
{
	t_vec	c;
	t_vec	color;
	double	r;
	double	fuzz;

	if (!(ft_arrsize(line) == 5 || ft_arrsize(line) == 6)
		|| !ft_atod(&r, line[2])
		|| !ft_atod(&fuzz, line[4])
		|| !parse_split(&c, line[1])
		|| !parse_split(&color, line[3]))
		return (ERROR);
	if (!add_world(SPHERE, 1,
			create_sphere(c, r),
			create_metal(create_texture(color, line[5]), fuzz)))
		return (ERROR);
	return (OK);
}

int	parse_sq_metal(char **line)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;
	double	side;
	double	fuzz;

	if (!(ft_arrsize(line) == 6 || ft_arrsize(line) == 7)
		|| !ft_atod(&side, line[3])
		|| !ft_atod(&fuzz, line[5])
		|| !parse_split(&c, line[1])
		|| !parse_split(&n, line[2])
		|| !parse_split(&color, line[4]))
		return (ERROR);
	if (!add_world(SQUARE, 1,
			create_square(c, n, side),
			create_metal(create_texture(color, line[6]), fuzz)))
		return (ERROR);
	return (OK);
}

int	parse_tr_metal(char **line)
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	t_clr	color;
	double	fuzz;

	if (!(ft_arrsize(line) == 6 || ft_arrsize(line) == 7)
		|| !ft_atod(&fuzz, line[5])
		|| !parse_split(&p1, line[1])
		|| !parse_split(&p2, line[2])
		|| !parse_split(&p3, line[3])
		|| !parse_split(&color, line[4]))
		return (ERROR);
	if (!add_world(TRIANGLE, 1,
			create_triangle(p1, p2, p3),
			create_metal(create_texture(color, line[6]), fuzz)))
		return (ERROR);
	return (OK);
}

int	parse_pl_metal(char **line)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;
	double	fuzz;

	if (!(ft_arrsize(line) == 5 || ft_arrsize(line) == 6)
		|| !ft_atod(&fuzz, line[4])
		|| !parse_split(&c, line[1])
		|| !parse_split(&n, line[2])
		|| !parse_split(&color, line[3]))
		return (ERROR);
	if (!add_world(PLANE, 1,
			create_plane(c, n),
			create_metal(create_texture(color, line[5]), fuzz)))
		return (ERROR);
	return (OK);
}

int	parse_cy_metal(char **line)
{
	t_pnt	c;
	t_vec	n;
	t_clr	color;
	double	data[2];
	double	fuzz;

	if (!(ft_arrsize(line) == 7 || ft_arrsize(line) == 8)
		|| !ft_atod(&data[R], line[3])
		|| !ft_atod(&data[H], line[4])
		|| !ft_atod(&fuzz, line[6])
		|| !parse_split(&c, line[1])
		|| !parse_split(&n, line[2])
		|| !parse_split(&color, line[5]))
		return (ERROR);
	if (!add_world(CYLINDER, 1,
			create_cylinder(c, n, data[R], data[H]),
			create_metal(create_texture(color, line[7]), fuzz)))
		return (ERROR);
	return (OK);
}
