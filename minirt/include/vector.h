#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdio.h>
// vector 구조체
typedef struct s_vec
{
	double x;
	double y;
	double z;
}		t_vec;

// ray 구조체
typedef struct s_ray
{
	t_vec origin;
	t_vec dir;
}	t_ray;

// ray member function
t_vec ray_at(t_ray *ray, double t);

// vector member function
t_vec vec(double x, double y, double z);
t_vec vec_cal(t_vec *v, double *a, int n);
t_vec vec_cross(t_vec *v1, t_vec *v2);
t_vec vec_unit(t_vec *vec);
void vec_print(t_vec *vec);
double vec_dot(t_vec *v1, t_vec *v2);

#endif
