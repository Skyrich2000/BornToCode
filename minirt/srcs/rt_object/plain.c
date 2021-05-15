#include "minirt.h"

t_object	create_plane(t_pnt origin, t_vec n, t_clr color)
{
	t_object obj;

	vec_print("plane origin", &origin);
	vec_print("plane n", &n);
	vec_print("plane color", &color);
	obj.plane.origin = origin;
	obj.plane.n = n;
	obj.plane.color = color;
	return (obj);
}

int hit_plane(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	double	t;
	double	d;

	ray->dir = vec_unit_(&ray->dir);
	d = vec_dot(ray->dir, this->obj.plane.n);
	if (ft_abs(d) < EPSILON)
		return (ERROR);
	t = vec_dot(vec_cal((t_vec[2]){this->obj.plane.origin, ray->origin}, (double[2]){1, -1}, 2), this->obj.plane.n) / d;
	if (t < minmax[0] || minmax[1] < t)			// 이때 min 은 ray의 시작점
		return (ERROR);
	rec->rayin = ray->dir;
	rec->albedo = this->albedo;
	rec->t = t;						// hit_record 에 위 식에서 나온 해를 저장한다(ray-hit_point사이 거리)
	rec->p = ray_at(ray, rec->t);	// 크기를 구했으니 ray에서 구까지의 벡터 p를 구한다.
	rec->n = this->obj.plane.n;
	rec->front_face = vec_dot_(&ray->dir, &rec->n) < 0;
	if (!rec->front_face) // 만약 위에서 구한 법선벡터와 ray의 방향벡터(어차피 둘다 단위벡터로 만들었음)의 내적값이 양수이면 예각이므로 n의 방향을 반대로 해주어야 한다
		rec->n = vec_cal((t_vec[1]){rec->n}, (double[1]){ -1}, 1);
	rec->material = &this->material;
	return (OK);
}
