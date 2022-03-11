#include "minirt.h"
#include <time.h>

t_camera	*init_camera(void)
{
	t_camera	*head;

	head = (t_camera *)malloc(sizeof(t_camera));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int	set_camera(t_camera *cam, t_vec lookfrom, t_vec dir, double fov)
{
	double		aperture;
	double		ratio;

	aperture = 2.0;
	ratio = m()->scr.wid / m()->scr.hei;
	cam->pos = lookfrom;
	cam->dir = dir;
	cam->view_height = 2.0 * tan((fov * M_PI / 180) / 2.0);
	cam->view_width = ratio * cam->view_height;
	cam->fov = fov;
	cam->w = vec_oppo(cam->dir);
	cam->u = vec_unit(vec_cross(vec(0, 1, 0), cam->w));
	cam->v = vec_cross(cam->w, cam->u);
	cam->hor = vec_muln(cam->u, cam->view_width);
	cam->ver = vec_muln(cam->v, cam->view_height);
	cam->low_left_corner = vec_cal(\
							(t_vec [4]){lookfrom, cam->hor, cam->ver, cam->w}, \
							(double [4]){1, -0.5, -0.5, -1}, \
							4);
	return (OK);
}

int	add_camera(t_camera *head, t_vec lookfrom, t_vec dir, double fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (ERROR);
	set_camera(cam, lookfrom, dir, fov);
	cam->img = 0;
	cam->next = head->next;
	cam->render_index = 0;
	head->next = cam;
	return (OK);
}
