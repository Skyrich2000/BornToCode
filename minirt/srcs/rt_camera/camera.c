#include "minirt.h"

void	create_camera(t_camera *cam, t_vec pos, double height, double ratio)
{
	cam->pos = pos;
	cam->view_width = ratio * 2;
	cam->view_height = 2;
	cam->focal_length = vec(0, 0, 1);
	cam->horizon = vec(cam->view_width, 0, 0);
	cam->vertical = vec(0, cam->view_height, 0);
	cam->low_left_corner = vec_cal((t_vec[4]){cam->pos, cam->horizon, cam->vertical, cam->focal_length}, \
									(double [4]){1, -0.5, -0.5, -1}, 4);
}
