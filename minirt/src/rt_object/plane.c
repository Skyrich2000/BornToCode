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

	d = vec_dot_(&ray->dir, &n_value);
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

int	hit_plane(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	if (!get_plane_t(&this->obj.plane, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.plane.n;
	set_rec(this, ray, rec);
	return (OK);
}
