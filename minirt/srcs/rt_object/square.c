#include "minirt.h"

t_object	create_square(t_pnt c, t_vec n, double side)
{
	t_object obj;

	vec_print("square center", &c);
	vec_print("square center", &n);
	obj.square.c = c;
	obj.square.n = n;
	obj.square.side = side;
	return (obj);
}

static int get_t(t_world *this, t_ray *ray, double minmax[2], double *t)
{
	double	d;
	double	cos_theta;
	double	limit;
	t_vec p;
	t_vec random_vector;
	t_vec side_vecter;
	t_vec cp;

	d = vec_dot(ray->dir, this->obj.square.n);
	if (ft_abs(d) < EPSILON)
		return (ERROR);
	*t = vec_dot(vec_cal((t_vec[2]){this->obj.square.c, ray->origin}, (double[2]){1, -1}, 2), this->obj.square.n) / d;
	if (*t < minmax[0] || minmax[1] < *t)			// 이때 min 은 ray의 시작점
		return (ERROR);
	p = ray_at(ray, *t);
	random_vector = vec(0, 1, 0);
	if (ft_abs(this->obj.square.n.y) == 1)
		random_vector = vec(1, 0, 0);
	side_vecter = vec_cross_(&this->obj.square.n, &random_vector);
	cp = vec_cal((t_vec[2]){p, this->obj.square.c}, (double[2]){1, -1}, 2);
	cos_theta = ft_abs(vec_dot_(&side_vecter, &cp) / (vec_length(&side_vecter) * vec_length(&cp)));
	if (cos_theta < sqrt(2) / 2)
		cos_theta = cos(M_PI_2 - acos(cos_theta));
	limit = (this->obj.square.side / 2) / cos_theta;
	if (vec_length_squared(&cp) > limit * limit)
		return (ERROR);
	return (OK);
}

int hit_square(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec)
{
	if (!get_t(this, ray, minmax, &rec->t))
		return (ERROR);
	rec->p = ray_at(ray, rec->t);
	rec->n = this->obj.square.n;
	set_rec(this, ray, rec);
	return (OK);
}
