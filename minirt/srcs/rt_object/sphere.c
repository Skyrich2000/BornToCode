#include "object.h"

t_object set_sphere(t_vec c, double r)
{
	t_object obj;

	obj.sphere.c = c;
	obj.sphere.r = r;
	return (obj);
}

int hit_sphere(t_object *obj, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	double t;
	t_vec oc;

	oc = vec_cal((t_vec[2]){ray->origin, obj->sphere.c} \
				,(double[2]){1, -1}, 2);
	double a = vec_dot(&ray->dir, &ray->dir);
	double half_b = vec_dot(&oc, &ray->dir);
	double c = vec_dot(&oc, &oc) - obj->sphere.r * obj->sphere.r;
	double discriminant = half_b*half_b - a*c;
	if (discriminant < 0)
		return 0;
	t = (-half_b - sqrt(discriminant)) / a;
	if (t < minmax[0] || minmax[1] < t) {
		t = (-half_b + sqrt(discriminant)) / a;
		if (t < minmax[0] || minmax[1] < t)
			return 0;
	}

	rec->t = t;
	rec->p = ray_at(ray, rec->t);
	rec->n = vec_cal((t_vec[2]){rec->p, obj->sphere.c}, (double[2]){1, -1}, 2);
	rec->n = vec_unit(&rec->n);
	return 1;
}
