/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_save.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 04:48:20 by ycha              #+#    #+#             */
/*   Updated: 2022/04/16 04:48:21 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_printf.h"
#include "minirt.h"

static void	fd_print_double(int fd, double n, char *str)
{
	double	integer;
	double	fraction;

	fraction = round(fabs(modf(n, &integer) * 10000));
	if (-1 < n && n < 0)
		ft_fprintf(fd, "-%02d.%04d%s", (int)integer, (int)fraction, str);
	else
		ft_fprintf(fd, "%03d.%04d%s", (int)integer, (int)fraction, str);
}

static void	fd_print_vec(int fd, t_vec v, char *str)
{
	fd_print_double(fd, v.x, ",");
	fd_print_double(fd, v.y, ",");
	fd_print_double(fd, v.z, str);
}

static void	fd_print_camera(int fd)
{
	t_camera	*c;

	c = m()->cam->next;
	ft_fprintf(fd, "c\t\t\t\t");
	fd_print_vec(fd, c->pos, "\t");
	fd_print_vec(fd, c->dir, "\t");
	fd_print_double(fd, c->fov, "\n");
	c = c->next;
	while (c != m()->cam->next)
	{
		ft_fprintf(fd, "c\t\t\t\t");
		fd_print_vec(fd, c->pos, "\t");
		fd_print_vec(fd, c->dir, "\t");
		fd_print_double(fd, c->fov, "\n");
		c = c->next;
	}
	ft_fprintf(fd, "\n");
}

static void	fd_print_light(int fd)
{
	t_light	*l;

	l = m()->light->next;
	while (l)
	{
		ft_fprintf(fd, "l\t\t\t\t");
		fd_print_vec(fd, l->origin, "\t");
		fd_print_double(fd, l->ratio, "\t\t\t\t\t\t\t\t\t\t\t\t");
		fd_print_vec(fd, vec_muln(l->color, 255), "\n");
		l = l->next;
	}
	ft_fprintf(fd, "\n");
}

void	fd_print_material_name(int fd, char *oname, t_world *w)
{
	const char	mname[3][15] = {"lambertian", "metal", "dielectric"};

	ft_fprintf(fd, "%s", oname);
	if (w->is_material_fixed)
	{
		ft_fprintf(fd, "-%s\t", mname[w->material.type]);
		if (w->material.type == MATERIAL_METAL)
			ft_fprintf(fd, "\t");
	}
	else
		ft_fprintf(fd, "\t\t\t\t");
}

void	fd_print_material(int fd, t_world *w)
{
	fd_print_vec(fd, vec_muln(w->material.texture.color, 255), "\t");
	if (w->is_material_fixed)
	{
		if (w->material.type == MATERIAL_METAL)
			fd_print_double(fd, w->material.fuzz, "\t");
		else if (w->material.type == MATERIAL_DIELECTRIC)
			fd_print_double(fd, w->material.ir, "\t");
		else
			ft_fprintf(fd, "\t\t\t");
	}
	else
		ft_fprintf(fd, "\t\t\t");
}

void	fd_print_texture(int fd, t_world *w)
{
	if (w->material.texture.file_name)
		ft_fprintf(fd, "%s", w->material.texture.file_name);
	ft_fprintf(fd, "\n");
}

void	fd_print_plane(int fd, t_world *w, t_plane *pl)
{
	fd_print_material_name(fd, "pl", w);
	fd_print_vec(fd, pl->c, "\t");
	fd_print_vec(fd, pl->n, "\t\t\t\t\t\t\t\t");
	fd_print_material(fd, w);
	fd_print_texture(fd, w);
}

void	fd_print_sphere(int fd, t_world *w, t_sphere *sp)
{
	fd_print_material_name(fd, "sp", w);
	fd_print_vec(fd, sp->c, "\t");
	fd_print_double(fd, sp->r * 2, "\t\t\t\t\t\t\t\t\t\t\t\t");
	fd_print_material(fd, w);
	fd_print_texture(fd, w);
}

void	fd_print_cylinder(int fd, t_world *w, t_cylinder *cy)
{
	fd_print_material_name(fd, "cy", w);
	fd_print_vec(fd, cy->c, "\t");
	fd_print_vec(fd, cy->n, "\t");
	fd_print_double(fd, cy->r, " ");
	fd_print_double(fd, cy->h, "\t\t\t");
	fd_print_material(fd, w);
	fd_print_texture(fd, w);
}

void	fd_print_square(int fd, t_world *w, t_square *sq)
{
	fd_print_material_name(fd, "sq", w);
	fd_print_vec(fd, sq->c, "\t");
	fd_print_vec(fd, sq->n, "\t");
	fd_print_double(fd, sq->side, "\t\t\t\t\t");
	fd_print_material(fd, w);
	fd_print_texture(fd, w);
}

void	fd_print_triangle(int fd, t_world *w, t_triangle *tr)
{
	fd_print_material_name(fd, "tr", w);
	fd_print_vec(fd, tr->p1, "\t");
	fd_print_vec(fd, tr->p2, "\t");
	fd_print_vec(fd, tr->p3, "\t");
	fd_print_material(fd, w);
	fd_print_texture(fd, w);
}

void	fd_print_world(int fd)
{
	t_world	*w;

	w = m()->wrd;
	while (w->next)
	{
		w = w->next;
		if (w->type == PLANE)
			fd_print_plane(fd, w, &w->obj.plane);
		else if (w->type == SPHERE)
			fd_print_sphere(fd, w, &w->obj.sphere);
		else if (w->type == CYLINDER)
			fd_print_cylinder(fd, w, &w->obj.cylinder);
		else if (w->type == SQUARE)
			fd_print_square(fd, w, &w->obj.square);
		else if (w->type == TRIANGLE)
			fd_print_triangle(fd, w, &w->obj.triangle);
	}
	ft_fprintf(fd, "\n");
}

void	key_save(void)
{
	int	fd;

	fd = open("out.rt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
		return ;
	ft_fprintf(fd, "R\t\t\t\t");
	fd_print_double(fd, m()->scr.wid, " ");
	fd_print_double(fd, m()->scr.hei, "\n");
	ft_fprintf(fd, "A\t\t\t\t");
	fd_print_double(fd, m()->light->ratio, "\t\t\t\t\t");
	fd_print_vec(fd, vec_muln(m()->light->color, 255), "\n\n");
	fd_print_camera(fd);
	fd_print_light(fd);
	fd_print_world(fd);
	close(fd);
}
