/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:33:26 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:33:27 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	create_sphere(t_vec c, double r)
{
	t_object	obj;

	vec_print("sphere", &c);
	obj.sphere.c = c;
	obj.sphere.r = r / 2;
	return (obj);
}

int	get_sphere_t(t_sphere *sp, t_ray *ray, double minmax[2], double *t)
{
	double	a;
	double	half_b;
	double	c;
	double	discriminant;
	t_vec	oc;

	oc = vec_cal((t_vec [2]){ray->origin, sp->c}, (double [2]){1, -1}, 2);
	a = vec_length_squared_(&ray->dir);
	half_b = vec_dot_(&oc, &ray->dir);
	c = vec_length_squared_(&oc) - sp->r * sp->r;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (ERROR);
	*t = (-half_b - sqrt(discriminant)) / a;
	if (*t < minmax[0] || minmax[1] < *t)
	{
		*t = (-half_b + sqrt(discriminant)) / a;
		if (*t < minmax[0] || minmax[1] < *t)
			return (ERROR);
	}
	return (OK);
}

void	get_sphere_uv(t_hit_record *rec)
{
	const t_vec		*p = &rec->n;
	const double	theta = acos(p->y);
	const double	phi = atan2(-p->z, p->x) + M_PI;

	rec->u = phi / (2 * M_PI);
	rec->v = theta / M_PI;
}

int	hit_sphere(t_world *this, t_ray *ray, double minmax [2], t_hit_record *rec)
{
	if (!get_sphere_t(&this->obj.sphere, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = vec_cal((t_vec [2]){rec->p, this->obj.sphere.c}, \
			(double [2]){1 / this->obj.sphere.r, -1 / this->obj.sphere.r}, 2);
	if (m()->texture_toggle)
		get_sphere_uv(rec);
	set_rec(this, ray, rec);
	return (OK);
}
