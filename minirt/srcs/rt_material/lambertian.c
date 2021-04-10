#include "material.h"

void init_lambertian(t_vec color)
{

}

t_object init_sphere(t_vec c, double r)
{
	t_object obj;

	obj.sphere.c = c;
	obj.sphere.r = r;
	return (obj);
}

int scatter_lambertian(t_ray *ray_in, t_hit_record *rec, t_vec *color, t_ray *ray_out)
{
	t_vec target;

	target = vec_cal((t_vec[2]){rec->p, random_in_hemisphere(&rec->n)}, (double[2]){1, 1} ,3); // or random_unit_vector
	ray_out->origin = rec->p; // random value에 의한 정점좌표를 새로 지정
	ray_out->dir = vec_cal((t_vec[2]){target, rec->p},(double[2]){1, -1} ,2);
	return (1);
}
