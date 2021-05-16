#include "minirt.h"

t_object create_sphere(t_vec c, double r)
{
	t_object obj;

	vec_print("sphere", &c);
	obj.sphere.c = c;
	obj.sphere.r = r /2;
	return (obj);
}

int get_sphere_t(t_sphere *sp, t_ray *ray, double minmax[2], double *t)
{
	double a;
	double half_b;
	double c;
	double discriminant;
	t_vec oc;

	oc = vec_cal((t_vec[2]){ray->origin, sp->c}, (double[2]){1, -1}, 2);
	a = vec_length_squared_(&ray->dir);
	half_b = vec_dot_(&oc, &ray->dir);
	c = vec_length_squared_(&oc) - sp->r * sp->r;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (ERROR);
	*t = (-half_b - sqrt(discriminant)) / a;			// t 값을 구하는데 min < t < max 인 값을 구한다
	if (*t < minmax[0] || minmax[1] < *t) {			// 이때 min 은 ray의 시작점
		*t = (-half_b + sqrt(discriminant)) / a;		// max 는 min(INF, 이전에 나왔던 t값) 이다
		if (*t < minmax[0] || minmax[1] < *t)
			return (ERROR);
	}
	return (OK);
}

int hit_sphere(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	if (!get_sphere_t(&this->obj.sphere, ray, minmax, &rec->t)) // hit_record 에 위 식에서 나온 해를 저장한다(ray-hit_point사이 거리)
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = vec_cal((t_vec[2]){rec->p, this->obj.sphere.c}, (double[2]){1 / this->obj.sphere.r, -1 / this->obj.sphere.r}, 2); // P - C를 한 뒤 반지름을 나눠서 단위벡터를 구한다
	set_rec(this, ray, rec);
	return (OK);
}
