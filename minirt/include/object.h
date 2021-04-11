// 구, 원기둥 등 구조체 생성
#ifndef OBJECT_H
# define OBJECT_H
# include "vector.h"
# include "material.h"
# include <stdlib.h>

typedef struct s_sphere
{
	t_vec	c;
	double	r;
	int		inside;
}				t_sphere;

typedef struct s_plane
{
	t_vec	p;
}				t_plane;

typedef struct s_square
{
	t_vec	c;
	double	side;

}				t_square;

typedef struct s_cylinder
{
	t_vec	c;
	t_vec	nv;
	double	r;
	double	h;
	double	dist1;
	double	dist2;
}				t_cylinder;

typedef struct s_triangle
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
}				t_triangle;

typedef union u_object
{
	t_cylinder	cylinder;
	t_triangle	triangle;
	t_square	square;
	t_sphere	sphere;
	t_plane		plane;
}		t_object;

typedef struct s_material t_material;

typedef struct s_hit_record
{
	t_vec	p;	// ray에서 구위의 점으로 향하는 벡터 p
	t_vec	n;	// 해당 좌표에서의 법선벡터 n
	double	t;	// ray가 구와 충돌한 지점 사이의 크기
	int		front_face;
	t_material	*material;
	// material 구조체 안쓰고
	// scatter , ray_in, ray_out, color 넣을까..? - huni
}				t_hit_record;

typedef struct s_world
{
	t_object	obj;
	t_material	*material;
	int			(*hit)(struct s_world *this, t_ray *ray, double minmax[2], t_hit_record *out);
	struct s_world		*next;
}				t_world;

t_world		*init_world(void); // create world?
int			add_world(t_world *head, t_object obj, int (*hit)(t_world *this, t_ray *ray, double minmax[2], t_hit_record *out), t_material *material);
int			hit_world(t_world *head, t_ray *ray, double minmax[2], t_hit_record *out);

t_object	create_sphere(t_vec c, double r);

int			hit_sphere(t_world *this, t_ray *ray, double minmax[2], t_hit_record *rec);

#endif
