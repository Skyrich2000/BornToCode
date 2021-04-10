#include "vector.h"
#include "library.h"
void vec_print(t_vec *vec)
{
	printf("[%.2f, %.2f, %.2f]", vec->x, vec->y, vec->z);
}

t_vec vec(double x, double y, double z)
{
	t_vec out;

	out.x = x;
	out.y = y;
	out.z = z;
	return (out);
}

t_vec vec_cross(t_vec *v1, t_vec *v2)
{
	t_vec out;

	out.x = v1->y * v2->z + v1->z * v2->y;
	out.y = v1->z * v2->x + v1->x * v2->z;
	out.z = v1->x * v2->y + v1->y * v2->x;
	return (out);
}

double vec_dot(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double vec_length_squared(t_vec *vec)
{
	return (vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

double vec_length(t_vec *vec)
{
	double len;

	len = vec_length_squared(vec);
	len = sqrt(len);
	return (len);
}

t_vec	vec_unit(t_vec *v)
{
	double len;

	len = vec_length(v);
	return (vec(v->x / len
			, v->y / len
			, v->z / len));
}

t_vec	ray_at(t_ray *ray, double t)
{
	return (vec(ray->origin.x + ray->dir.x * t
			, ray->origin.y + ray->dir.y * t
			, ray->origin.z + ray->dir.z * t));
}

t_vec	vec_cal(t_vec *v, double *a, int n)
{
	t_vec out;

	out = vec(0, 0, 0);
	while (n--)
	{
		out.x += v[n].x * a[n];
		out.y += v[n].y * a[n];
		out.z += v[n].z * a[n];
	}
	return (out);
}

t_vec	vec_add(t_vec v, double a)
{
	return (vec(v.x + a, v.y + a, v.z + a));
}

t_vec	random_in_unit_sphere()
{
	t_vec out;

	while (1)
	{
		out = vec(rand_num(1, -1, 1), rand_num(1, -1, 1), rand_num(1, -1, 1));
		if (vec_length_squared(&out) >= 1)
			continue ;
		return (out);
	}
}

t_vec	random_unit_vector()
{
	t_vec tmp;

	tmp = random_in_unit_sphere();
	return vec_unit(&tmp);
}

t_vec	random_in_hemisphere(t_vec *normal)
{
	t_vec in_unit_sphere = random_in_unit_sphere();

	if (vec_dot(&in_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
		return in_unit_sphere;
	else
		return vec_cal((t_vec[1]){in_unit_sphere}, (double[1]){-1}, 1);
}
