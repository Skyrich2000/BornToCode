#include "material.h"

t_material create_metal(t_vec color, double fuzz)
{
	t_material mat;

	mat.color = color;
	mat.scatter = scatter_metal;
	mat.fuzz = 1;
	if (fuzz < 1)
		mat.fuzz = fuzz;
	return (mat);
}

static t_vec reflect(t_vec *v, t_vec *n)
{
    return (vec_cal((t_vec[2]){*v, *n}, (double[2]){1, -2 * vec_dot(v, n)}, 2));
}

int scatter_metal(t_material *this, t_ray *ray_in, t_hit_record *rec, t_ray *ray_out)
{
	t_vec ray_in_dir_unit;
	t_vec target;

	ray_in_dir_unit = vec_unit(&ray_in->dir);
	target = reflect(&ray_in_dir_unit, &rec->n); // or random_unit_vector + near_zero
	target = vec_cal((t_vec[2]){target, random_in_unit_sphere()}, (double[2]){1, this->fuzz}, 2);
	ray_out->origin = rec->p; // random value에 의한 정점좌표를 새로 지정
	ray_out->dir = target;
	return (vec_dot(&target, &rec->n) > 0);
}
