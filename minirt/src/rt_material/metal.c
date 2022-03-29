#include "minirt.h"

t_material	create_metal(t_texture texture, double fuzz)
{
	t_material	mat;

	mat.texture = texture;
	mat.scatter = scatter_metal;
	mat.fuzz = 1;
	if (fuzz < 1)
		mat.fuzz = fuzz;
	return (mat);
}

// or random_unit_vector + near_zero
// random value에 의한 정점좌표를 새로 지정
int	scatter_metal(
	t_material *this,
	t_ray *ray_in,
	t_hit_record *rec,
	t_ray *ray_out
) {
	t_vec	ray_in_dir_unit;
	t_vec	target;

	ray_in_dir_unit = vec_unit_(&ray_in->dir);
	target = reflect_(&ray_in_dir_unit, &rec->n);
	target = vec_cal((t_vec [2]){target, random_in_unit_sphere()}, \
								(double [2]){1, this->fuzz}, 2);
	ray_out->origin = rec->p;
	ray_out->dir = target;
	return (vec_dot_(&target, &rec->n) > 0);
}
