#include "minirt.h"

t_material	create_dielectric(double ir)
{
	t_material	mat;

	mat.color = vec(1.0, 1.0, 1.0);
	mat.ir = ir;
	mat.scatter = scatter_dielectric;
	return (mat);
}

// double r0 = (1-ref_idx) / (1+ref_idx);
//         r0 = r0*r0;
static double	reflectance(double cos_theta, double ir)
{
	return (ir * (1 - ir) * pow(1 - cos_theta, 5));
}

// abs 왜 있음?
static t_vec	refract(t_vec *r_in, t_vec *n, double ir, double cos_theta)
{
	const t_vec	r_in_value = *r_in;
	const t_vec	n_value = *n;
	t_vec		r_out_perp;
	t_vec		r_out_parallel;

	r_out_perp = vec_cal((t_vec [2]){r_in_value, n_value}, \
						(double [2]){1 * ir, cos_theta * ir}, 2);
	r_out_parallel = vec_cal((t_vec [1]){n_value}, \
							(double [1]){-1 * sqrt(\
							ft_abs(1.0 - vec_length_squared_(&r_out_perp)))}, \
							1);
	return (vec_cal((t_vec [2]){r_out_perp, r_out_parallel}, \
					(double [2]){1, 1}, 2));
}

// min 왜함?
// || reflectance(cos_theta, this->ir) > rand_num(0, 0, 0))
// random value에 의한 정점좌표를 새로 지정
int	scatter_dielectric(
	t_material *this,
	t_ray *ray_in,
	t_hit_record *rec,
	t_ray *ray_out
) {
	t_vec	target;
	double	refraction_ratio;
	t_vec	ray_in_dir_unit;
	t_vec	ray_in_dir_unit_minus;
	double	cos_theta;
	double	sin_theta;

	refraction_ratio = this->ir;
	if (rec->front_face)
		refraction_ratio = 1.0 / this->ir;
	ray_in_dir_unit = vec_unit_(&ray_in->dir);
	ray_in_dir_unit_minus = vec_cal((t_vec [1]){ray_in_dir_unit}, \
														(double [1]){-1}, 1);
	cos_theta = ft_min(vec_dot_(&ray_in_dir_unit_minus, &rec->n), 1.0);
	sin_theta = sqrt(1 - pow(cos_theta, 2));
	if (refraction_ratio * sin_theta > 1.0)
		target = reflect_(&ray_in_dir_unit, &rec->n);
	else
		target = refract(&ray_in_dir_unit, &rec->n, \
												refraction_ratio, cos_theta);
	ray_out->origin = rec->p;
	ray_out->dir = target;
	return (OK);
}
