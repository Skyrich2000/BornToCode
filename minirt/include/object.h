// 구, 원기둥 등 구조체 생성
#ifndef OBJECT_H
# define OBJECT_H
# include "vector.h"

typedef struct	s_sphere
{
	t_vec	c;
	double	r;
	int		inside;
}				t_sphere;

typedef struct	s_plane
{
	t_vec	p;
}				t_plane;

typedef struct	s_square
{
	t_vec	c;
	double	side;

}				t_square;

typedef struct	s_cylinder
{
	t_vec	c;
	t_vec	nv;
	double	r;
	double	h;
	double	dist1;
	double	dist2;
}				t_cylinder;

typedef struct	s_triangle
{
	t_vec	p1;
	t_vec	p2;
	t_vec	p3;
}				t_triangle;

typedef union u_object
{
	t_cylinder cylinder;
	t_triangle triangle;
	t_square square;
	t_sphere sphere;
	t_plane plane;
}		t_object;

typedef struct	s_hit_record
{
	t_vec p;
	t_vec n;
	double t;
}				t_hit_record;

typedef struct	s_world
{
	t_object obj;
	int (*hit)(t_object *obj, t_ray *ray, double minmax[2], t_hit_record *out);
	struct s_world	*next;
}				t_world;

t_world		*world_init();
int	world_add(t_world *head, t_object obj, int (*hit)(t_object *obj, t_ray *ray, double minmax[2], t_hit_record *out));
int	world_hit(t_world *head, t_ray *ray, double minmax[2], t_hit_record *out);

t_object set_sphere(t_vec c, double r);
int hit_sphere(t_object *obj, t_ray *ray, double minmax[2], t_hit_record *rec);
// double hit_triangle(t_triangle triangle, t_ray *ray, double t_min, double t_max, t_hit_record *rec);
// double hit_cylinder(t_cylinder cylinder, t_ray *ray, double t_min, double t_max, t_hit_record *rec);
// double hit_square(t_square square, t_ray *ray, double t_min, double t_max, t_hit_record *rec);
// double hit_plane(t_plane plane, t_ray *ray, double t_min, double t_max, t_hit_record *rec);

#endif