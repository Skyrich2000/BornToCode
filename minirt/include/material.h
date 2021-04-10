#ifndef MATERIAL_H
#define MATERIAL_H
# include <stdio.h>
# include "vector.h"

// vector 구조체
typedef struct	s_material
{
	t_vec 	color;
}				t_material;

// ray 구조체
typedef struct	s_ray
{
	t_vec	origin;
	t_vec	dir;
}				t_ray;

// ray member function
t_vec	ray_at(t_ray *ray, double t);

// vector member function
t_vec	vec(double x, double y, double z);
t_vec	vec_cal(t_vec *v, double *a, int n);
t_vec	vec_add(t_vec v, double a);
t_vec	vec_cross(t_vec *v1, t_vec *v2);
t_vec	vec_unit(t_vec *vec);
t_vec	random_in_unit_sphere(void);
t_vec	random_unit_vector(void);
t_vec	random_in_hemisphere(t_vec *normal);
void	vec_print(t_vec *vec);
double	vec_dot(t_vec *v1, t_vec *v2);
double	vec_length_squared(t_vec *vec);

#endif
