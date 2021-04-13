#include "minirt.h"

void	create_camera(t_camera *cam, t_vec lookfrom, t_vec lookat, t_vec vup, double vfov, double ratio, double aperture, double dist_to_focus)
{
	cam->pos = lookfrom;
	cam->view_height = 2.0 * tan((vfov * M_PI / 180) / 2.0);
	cam->view_width = ratio * cam->view_height;
	cam->w = vec_cal((t_vec[2]){lookfrom, lookat}, (double[2]){1, -1}, 2);
	cam->w = vec_unit(&cam->w);
	cam->u = vec_cross(&vup, &cam->w);
	cam->u = vec_unit(&cam->u);
	cam->v = vec_cross(&cam->w, &cam->u);

	cam->horizon = vec_cal((t_vec[1]){cam->u}, (double[1]){cam->view_width * dist_to_focus}, 1);
	cam->vertical = vec_cal((t_vec[1]){cam->v}, (double[1]){cam->view_height * dist_to_focus}, 1);
	cam->low_left_corner = vec_cal((t_vec[4]){lookfrom, cam->horizon, cam->vertical, cam->w}, \
									(double [4]){1, -0.5, -0.5, -dist_to_focus}, 4);

	cam->lens_radius = aperture / 2;
}
