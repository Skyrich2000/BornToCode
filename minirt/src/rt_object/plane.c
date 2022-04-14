/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:32:28 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:32:29 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	create_plane(t_pnt c, t_vec n)
{
	t_object	obj;

	vec_print("plane c", &c);
	vec_print("plane n", &n);
	obj.plane.c = c;
	obj.plane.n = n;
	return (obj);
}

int	_get_plane_t(t_vec *v[2], t_ray *ray, double minmax[2], double *t)
{
	const t_vec	c_value = *v[0];
	const t_vec	n_value = *v[1];
	double		d;

	d = vec_dot_(&ray->dir, v[1]);
	if (ft_abs(d) < EPSILON)
		return (ERROR);
	*t = vec_dot(vec_cal((t_vec [2]){c_value, ray->origin}, \
										(double [2]){1, -1}, 2), n_value) / d;
	if (*t < minmax[0] || minmax[1] < *t)
		return (ERROR);
	return (OK);
}

int	get_plane_t(t_plane *pl, t_ray *ray, double minmax[2], double *t)
{
	return (_get_plane_t((t_vec *[2]){&pl->c, &pl->n}, ray, minmax, t));
}

// https://gamedev.stackexchange.com/questions
//				/172352/finding-texture-coordinates-for-plane
void	get_plane_uv(t_hit_record *rec, t_pnt c, double size)
{
	const t_vec		p = vec_sub(rec->p, c);
	const t_vec		n = rec->n;
	t_vec			e1;
	t_vec			e2;

	e1 = vec_unit(vec_cross(n, vec(0, 1, 0)));
	if (e1.x == 0 && e1.y == 0 && e1.z == 0)
		e1 = vec_unit(vec_cross(n, vec(0, 0, 1)));
	e2 = vec_unit(vec_cross(n, e1));
	rec->u = vec_dot(e1, p) / size;
	rec->v = vec_dot(e2, p) / size;
	rec->u = (rec->u + 1) / 2;
	rec->v = (rec->v + 1) / 2;
}

int	hit_plane(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	if (!get_plane_t(&this->obj.plane, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.plane.n;
	if (m()->texture_toggle)
		get_plane_uv(rec, this->obj.plane.c, 1);
	set_rec(this, ray, rec);
	return (OK);
}
