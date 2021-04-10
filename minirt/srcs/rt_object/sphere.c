#include "object.h"

t_object init_sphere(t_vec c, double r)
{
	t_object obj;

	obj.sphere.c = c;
	obj.sphere.r = r;
	return (obj);

}

int hit_sphere(t_object *obj, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	double t;
	double a;
	double half_b;
	double c;
	double discriminant;
	t_vec oc;

	oc = vec_cal((t_vec[2]){ray->origin, obj->sphere.c} \
				,(double[2]){1, -1}, 2);
	a = vec_length_squared(&ray->dir);
	half_b = vec_dot(&oc, &ray->dir);
	c = vec_length_squared(&oc) - obj->sphere.r * obj->sphere.r;
	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return 0;
	t = (-half_b - sqrt(discriminant)) / a;			// t 값을 구하는데 min < t < max 인 값을 구한다
	if (t < minmax[0] || minmax[1] < t) {			// 이때 min 은 ray의 시작점
		t = (-half_b + sqrt(discriminant)) / a;		// max 는 min(INF, 이전에 나왔던 t값) 이다
		if (t < minmax[0] || minmax[1] < t)
			return 0;
	}
	rec->t = t;						// hit_record 에 위 식에서 나온 해를 저장한다(ray-hit_point사이 거리)
	rec->p = ray_at(ray, rec->t);	// 크기를 구했으니 ray에서 구까지의 벡터 p를 구한다.
	rec->n = vec_cal((t_vec[2]){rec->p, obj->sphere.c}, (double[2]){1 / obj->sphere.r, -1 / obj->sphere.r}, 2); // P - C를 한 뒤 반지름을 나눠서 단위벡터를 구한다
	if (vec_dot(&ray->dir, &rec->n) > 0) // 만약 위에서 구한 법선벡터와 ray의 방향벡터(어차피 둘다 단위벡터로 만들었음)의 내적값이 양수이면 예각이므로 n의 방향을 반대로 해주어야 한다
		rec->n = vec_cal((t_vec[1]){rec->n}, (double[1]){ -1}, 1);
	return 1;
}
