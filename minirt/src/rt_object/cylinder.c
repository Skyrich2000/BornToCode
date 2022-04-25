/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:13:58 by echung            #+#    #+#             */
/*   Updated: 2022/04/25 19:48:53 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	create_cylinder(t_pnt c, t_vec n, double r, double h)
{
	t_object	obj;

	obj.cylinder.c = c;
	obj.cylinder.n = n;
	obj.cylinder.r = r;
	obj.cylinder.h = h;
	obj.cylinder.top = vec_cal((t_vec [2]){c, n}, (double [2]){1, h / 2}, 2);
	obj.cylinder.bot = vec_cal((t_vec [2]){c, n}, (double [2]){1, -h / 2}, 2);
	return (obj);
}

static int	check_t(t_cylinder *cy, t_ray *ray, double t)
{
	t_vec	p;

	p = ray_at(ray, t);
	if (vec_dot(cy->n, \
			vec_cal((t_vec [2]){p, cy->top}, (double [2]){1, -1}, 2)) > 0)
		return (ERROR);
	if (vec_dot(cy->n, \
			vec_cal((t_vec [2]){p, cy->bot}, (double [2]){1, -1}, 2)) < 0)
		return (ERROR);
	return (OK);
}

int	get_cylinder_t(t_cylinder *cy, t_ray *ray, double minmax[2], double *t)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	t_vec	ca;

	ca = vec_cal((t_vec [2]){ray->origin, cy->c}, (double [2]){1, -1}, 2);
	a = vec_length_squared(vec_cross_(&ray->dir, &cy->n));
	half_b = vec_dot(vec_cross_(&ca, &cy->n), vec_cross_(&ray->dir, &cy->n));
	c = vec_length_squared(vec_cross_(&ca, &cy->n)) - cy->r * cy->r;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0 || ft_abs(vec_dot_(&cy->n, &ray->dir)) == 1)
		return (ERROR);
	*t = (-half_b - sqrt(discriminant)) / a;
	if (!check_t(cy, ray, *t) || *t < minmax[0] || minmax[1] < *t)
	{
		*t = (-half_b + sqrt(discriminant)) / a;
		if (!check_t(cy, ray, *t) || *t < minmax[0] || minmax[1] < *t)
			return (ERROR);
	}
	return (OK);
}

void	get_cylinder_uv(t_hit_record *rec, t_vec cp, t_cylinder *cy)
{
	const t_vec		p = cp;
	const t_vec		n = cy->n;
	t_vec			e1;
	t_vec			e2;
	double			phi;

	e1 = vec_unit(vec_cross(n, vec(0, 1, 0)));
	if (e1.x == 0 && e1.y == 0 && e1.z == 0)
		e1 = vec_unit(vec_cross(n, vec(0, 0, 1)));
	e2 = vec_unit(vec_cross(n, e1));
	phi = atan2(vec_dot(e2, p), vec_dot(e1, p)) + M_PI;
	rec->u = phi / (2 * M_PI);
	rec->v = vec_length(vec_sub(cp, vec_muln(rec->n, cy->r))) / (cy->h / 2);
	if (vec_dot(n, p) < 0)
		rec->v = -rec->v;
	rec->v = (rec->v + 1) / 2;
}

int	hit_cylinder(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	t_vec	cp;

	if (!get_cylinder_t(&this->obj.cylinder, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	cp = vec_cal((t_vec [2]){this->obj.cylinder.c, rec->p}, \
													(double [2]){1, -1}, 2);
	rec->n = vec_unit(vec_cross(this->obj.cylinder.n, \
									vec_cross_(&cp, &this->obj.cylinder.n)));
	get_cylinder_uv(rec, cp, &this->obj.cylinder);
	set_rec(this, ray, rec);
	return (OK);
}
