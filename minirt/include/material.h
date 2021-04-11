#ifndef MATERIAL_H
# define MATERIAL_H
# include <stdio.h>
# include "vector.h"
# include "object.h"

typedef struct s_hit_record t_hit_record;

// vector 구조체
typedef struct	s_material
{
	t_vec 	color;
	double	fuzz;
	double	ir;
	int (*scatter)(struct s_material *this, t_ray *ray_in, t_hit_record *rec, t_ray *ray_out);
}				t_material;

t_material create_lambertian(t_vec color);
t_material create_metal(t_vec color, double fuzz);
t_material create_dielectric(double ir);


int scatter_lambertian(struct s_material *this, t_ray *ray_in, t_hit_record *rec, t_ray *ray_out);
int scatter_metal(struct s_material *this, t_ray *ray_in, t_hit_record *rec, t_ray *ray_out);
int scatter_dielectric(t_material *this, t_ray *ray_in, t_hit_record *rec, t_ray *ray_out);

#endif
