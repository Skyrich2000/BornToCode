#include "minirt.h"

t_object	create_plane(t_pnt c, t_vec n)
{
	t_object obj;

	vec_print("plane c", &c);
	vec_print("plane n", &n);
	obj.plane.c = c;
	obj.plane.n = n;
	return (obj);
}

static int get_t(t_world *this, t_ray *ray, double minmax[2], double *t)
{
	double	d;

	d = vec_dot(ray->dir, this->obj.plane.n);
	if (ft_abs(d) < EPSILON)
		return (ERROR);
	*t = vec_dot(vec_cal((t_vec[2]){this->obj.plane.c, ray->origin}, (double[2]){1, -1}, 2), this->obj.plane.n) / d;
	if (*t < minmax[0] || minmax[1] < *t)			// 이때 min 은 ray의 시작점
		return (ERROR);
	return (OK);
}

int hit_plane(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	if (!get_t(this, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.plane.n;
	set_rec(this, ray, rec);
	return (OK);
}
