#ifndef MATERIAL_H
#define MATERIAL_H
# include <stdio.h>
# include "vector.h"
# include "object.h"

// vector 구조체
typedef struct	s_material
{
	t_vec 	color;
	int (*scatter)(t_ray *ray_in, t_hit_record *rec, t_vec *color, t_ray *ray_out);
}				t_material;

int scatter_lambertian(t_ray *ray_in, t_hit_record *rec, t_vec *color, t_ray *ray_out);

#endif
