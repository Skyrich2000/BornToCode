#include "minirt.h"
#include "vector.h"

void set_camera(t_camera *cam, t_vec pos, double height, double ratio)
{
	cam->pos = pos;
	cam->view_width = ratio * height;
	cam->view_height = height;
	cam->focal_length = vec(0, 0, 1); // 고정값
	cam->horizon = vec(cam->view_width, 0, 0);
	cam->vertical = vec(0, cam->view_height, 0);
	cam->low_left_corner = vec_cal((t_vec[4]){cam->pos, cam->horizon, cam->vertical, cam->focal_length}, \
									(double[4]){1, -0.5, -0.5, -1}, 4);
}
