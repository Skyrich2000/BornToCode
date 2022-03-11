#include "minirt.h"

t_vec	*get_object_pos(void *obj, int type)
{
	if (type == PLANE)
		return (&((t_plane *)obj)->c);
	if (type == SPHERE)
		return (&((t_sphere *)obj)->c);
	if (type == CYLINDER)
		return (&((t_cylinder *)obj)->c);
	if (type == TRIANGLE)
		return (&((t_triangle *)obj)->p1);
	if (type == SQUARE)
		return (&((t_square *)obj)->c);
	return (&((t_light *)obj)->origin);
}

t_vec	get_object_dir(void *obj, int type)
{
	if (type == PLANE)
		return (((t_plane *)obj)->n);
	if (type == SPHERE)
		return (vec(0, ((t_sphere *)obj)->r, 0));
	if (type == CYLINDER)
		return (((t_cylinder *)obj)->n);
	if (type == TRIANGLE)
		return (vec(0, 0, 0));
	if (type == SQUARE)
		return (((t_square *)obj)->n);
	return (vec(0, ((t_light *)obj)->ratio, 0));
}

void	set_object_pos(void *obj, int type, t_vec pos)
{
	if (type == TRIANGLE)
		set_triangle_pos(obj, pos);
	else if (type == CYLINDER)
		set_cylinder_pos(obj, pos);
	else
		*get_object_pos(obj, type) = pos;
}

void	set_object_dir(void *obj, int type, t_vec start, t_vec diff)
{
	if (type == PLANE)
		((t_plane *)obj)->n = vec_unit(vec_add(start, diff));
	else if (type == SPHERE)
		((t_sphere *)obj)->r = vec_add(start, diff).y;
	else if (type == CYLINDER)
	{
		((t_cylinder *)obj)->n = vec_unit(vec_add(start, diff));
		set_cylinder_pos(obj, ((t_cylinder *)obj)->c);
	}
	else if (type == SQUARE)
		((t_square *)obj)->n = vec_unit(vec_add(start, diff));
	else
		((t_light *)obj)->ratio = vec_add(start, diff).y;
}
