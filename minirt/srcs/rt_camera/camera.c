#include "minirt.h"

t_camera		*init_camera()
{
	t_camera	*head;

	head = (t_camera *)malloc(sizeof(t_camera));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int		add_camera(t_camera *head, t_vec lookfrom, t_vec dir, double vfov)
{
	t_camera *cam;
	double aperture = 2.0;
	double ratio = (16.0 / 9.0);

	cam = malloc(sizeof(t_camera));
	if (!cam)
		return (ERROR);
	cam->pos = lookfrom;
	cam->view_height = 2.0 * tan((vfov * M_PI / 180) / 2.0);
	cam->view_width = ratio * cam->view_height;
	cam->w = vec_cal((t_vec[1]){dir}, (double[1]){-1}, 1);
	cam->u = vec_unit(vec_cross(vec(0, 1, 0), cam->w));
	cam->v = vec_cross(cam->w, cam->u);
	cam->horizon = vec_cal((t_vec[1]){cam->u}, (double[1]){cam->view_width}, 1);
	cam->vertical = vec_cal((t_vec[1]){cam->v}, (double[1]){cam->view_height}, 1);
	cam->low_left_corner = vec_cal((t_vec[4]){lookfrom, cam->horizon, cam->vertical, cam->w}, \
									(double [4]){1, -0.5, -0.5, -1}, 4);
	// cam->lens_radius = aperture / 2;
	cam->img = 0;
	cam->next = head->next;
	head->next = cam;
	return (OK);
}

void	draw(t_minirt *m)
{
	if (!m->curr_cam->img)
	{
		m->curr_cam->img = mlx_new_image(m->scr.mlx, m->scr.width, m->scr.height);
		m->curr_cam->img_addr = mlx_get_data_addr(m->curr_cam->img, &m->scr.bits_per_pixel, &m->scr.line_length, &m->scr.endian);
		render(m);
	}
	mlx_put_image_to_window(m->scr.mlx, m->scr.win, m->curr_cam->img, 0, 0); // 생성한 이미지 객체 윈도우에 올리기
}
