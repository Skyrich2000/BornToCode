#include "minirt.h"

void	create_camera(t_camera *cam, t_vec lookfrom, t_vec lookat, t_vec vup, double vfov, double ratio)
{
	t_vec w;
	t_vec u;
	t_vec v;

	cam->pos = lookfrom;
	cam->view_height = 2.0 * tan((vfov * M_PI / 180) / 2.0);
	cam->view_width = ratio * cam->view_height;

	w = vec_cal((t_vec[2]){lookfrom, lookat}, (double[2]){1, -1}, 2);
	w = vec_unit(&w);
	u = vec_cross(&vup, &w);
	u = vec_unit(&u);
	v = vec_cross(&w, &u);

	vec_print(&w);
	vec_print(&u);
	vec_print(&v);

	cam->horizon = vec_cal((t_vec[1]){u}, (double[1]){cam->view_width}, 1);
	cam->vertical = vec_cal((t_vec[1]){v}, (double[1]){cam->view_height}, 1);
	cam->low_left_corner = vec_cal((t_vec[4]){cam->pos, cam->horizon, cam->vertical, w}, \
									(double [4]){1, -0.5, -0.5, -1}, 4);
}
