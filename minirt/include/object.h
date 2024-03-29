/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:32 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:51:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 구, 원기둥 등 구조체 생성
#ifndef OBJECT_H
# define OBJECT_H
# include "minirt.h"
# include <stdlib.h>

# define PLANE		0
# define SPHERE		1
# define CYLINDER	2
# define SQUARE		3
# define TRIANGLE	4
# define LIGHT		5

typedef struct s_sphere
{
	t_pnt	c;
	double	r;
	int		inside;
}	t_sphere;

typedef struct s_plane
{
	t_pnt	c;
	t_vec	n;
}	t_plane;

typedef struct s_square
{
	t_vec	c;
	t_vec	n;
	double	side;
}	t_square;

typedef struct s_cylinder
{
	t_vec	c;
	t_vec	n;
	double	r;
	double	h;
	t_vec	top;
	t_vec	bot;
}	t_cylinder;

typedef struct s_triangle
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
	t_vec	n;
	t_vec	e1;
	t_vec	e2;
	t_vec	e3;
}	t_triangle;

typedef union u_object
{
	t_cylinder	cylinder;
	t_triangle	triangle;
	t_square	square;
	t_sphere	sphere;
	t_plane		plane;
}	t_object;

typedef struct s_material	t_material;

typedef struct s_hit_record
{
	t_vec				p;
	t_vec				n;
	t_vec				rayin;
	double				t;
	double				u;
	double				v;
	int					front_face;
	int					is_material_fixed;
	struct s_material	*material;
}	t_hit_record;

typedef struct s_world
{
	int				type;
	int				is_material_fixed;
	t_object		obj;
	t_material		material;
	int				(*hit)(struct s_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *out);
	struct s_world	*next;
}	t_world;

t_world		*init_world(void);
int			add_world(int type, int is_material_fixed, \
										t_object obj, t_material material);
int			hit_world(t_ray *ray, double minmax[2], t_hit_record *out);
void		set_rec(t_world *this, t_ray *ray, t_hit_record *rec);
t_clr		get_rec_color(t_hit_record *rec);

t_object	create_sphere(t_vec c, double r);
int			hit_sphere(t_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *rec);

t_object	create_plane(t_pnt c, t_vec n);
int			hit_plane(t_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *rec);
int			_get_plane_t(t_vec *v[2], t_ray *ray, \
										double minmax[2], double *t);
void		get_plane_uv(t_hit_record *rec, t_pnt c, double size);

t_object	create_square(t_pnt c, t_vec n, double side);
int			hit_square(t_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *rec);

t_object	create_cylinder(t_pnt c, t_vec n, double r, double h);
void		set_triangle_pos(t_triangle *tr, t_pnt c);
int			hit_cylinder(t_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *rec);

t_object	create_triangle(t_vec p1, t_vec p2, t_vec p3);
int			hit_triangle(t_world *this, t_ray *ray, \
										double minmax[2], t_hit_record *rec);

#endif
