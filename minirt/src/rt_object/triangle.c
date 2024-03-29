/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:34:16 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:34:16 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	create_triangle(t_vec p1, t_vec p2, t_vec p3)
{
	t_object	obj;

	obj.triangle.p1 = p1;
	obj.triangle.p2 = p2;
	obj.triangle.p3 = p3;
	obj.triangle.e1 = vec_sub_(&p2, &p1);
	obj.triangle.e2 = vec_sub_(&p3, &p2);
	obj.triangle.e3 = vec_sub_(&p1, &p3);
	obj.triangle.n = vec_unit(vec_cross(obj.triangle.e1, \
										vec_oppo(obj.triangle.e3)));
	return (obj);
}

void	set_triangle_pos(t_triangle *tr, t_pnt c)
{
	tr->p1 = c;
	tr->p2 = vec_add(tr->p1, tr->e1);
	tr->p3 = vec_add(tr->p2, tr->e2);
}

int	get_triangle_t(t_triangle *tr, t_ray *ray, double minmax[2], double *t)
{
	t_vec	p;

	if (!_get_plane_t((t_vec *[2]){&tr->p1, &tr->n}, ray, minmax, t))
		return (ERROR);
	p = ray_at(ray, *t);
	if (vec_dot(tr->n, vec_cross(tr->e1, vec_sub(p, tr->p1))) < 0 || \
		vec_dot(tr->n, vec_cross(tr->e2, vec_sub(p, tr->p2))) < 0 || \
		vec_dot(tr->n, vec_cross(tr->e3, vec_sub(p, tr->p3))) < 0)
		return (ERROR);
	return (OK);
}

int	hit_triangle(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	if (!get_triangle_t(&this->obj.triangle, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.triangle.n;
	if (m()->texture_toggle)
		get_plane_uv(rec, this->obj.triangle.p1, \
									vec_length_(&this->obj.triangle.e1) / 2);
	set_rec(this, ray, rec);
	return (OK);
}
