#include "minirt.h"

static int	transfrom_3d_to_2d(t_camera *cam, t_vec *pos_3d, t_vec *pos_2d)
{
	const t_vec	R[3] = {
		{cam->u.x, cam->v.x, cam->dir.x},
		{cam->u.y, cam->v.y, cam->dir.y},
		{cam->u.z, cam->v.z, cam->dir.z},
	};
	const t_vec	R_t[3] = {
		{R[0].x, R[1].x, R[2].x},
		{R[0].y, R[1].y, R[2].y},
		{R[0].z, R[1].z, R[2].z},
	};
	const t_vec	pos_on_screen = {
		vec_dot_((t_vec *)&R_t[0], pos_3d),
		vec_dot_((t_vec *)&R_t[1], pos_3d),
		vec_dot_((t_vec *)&R_t[2], pos_3d),
	};
	double		x;
	double		y;

	x = pos_on_screen.x / cam->view_width * m()->scr.wid;
	y = m()->scr.hei - pos_on_screen.y / cam->view_height * m()->scr.hei;
	if (x < 0 || x > m()->scr.wid || y < 0 || y > m()->scr.hei)
		return (ERROR);
	*pos_2d = vec(x, y, 0);
	return (OK);
}

static int	get_screen_pos(t_camera *cam, t_vec world_pos, t_vec *screen_pos)
{
	double		t;
	t_ray		ray;
	t_vec		pos_on_cam;

	ray.origin = world_pos;
	ray.dir = vec_sub_(&cam->pos, &world_pos);
	if (!_get_plane_t((t_vec *[2]){&cam->low_left_corner, &cam->dir}, &ray, \
						(double [2]){0.001, 1.0}, &t))
		return (ERROR);
	if (t >= 1.0)
		return (ERROR);
	pos_on_cam = vec_sub(ray_at(&ray, t), cam->low_left_corner);
	if (!transfrom_3d_to_2d(cam, &pos_on_cam, screen_pos))
		return (ERROR);
	return (OK);
}

void	set_gui_objects(t_camera *cam)
{
	t_world		*w;

	cam->gui_object_top = 0;
	w = m()->wrd->next;
	while (w && w->next && cam->gui_object_top < MAX_GUI_OBJECT)
	{
		if (get_screen_pos(cam, w->obj.sphere.c, \
							&cam->gui_object[cam->gui_object_top].pos))
		{
			cam->gui_object[cam->gui_object_top].type = 0;
			cam->gui_object[cam->gui_object_top].obj = &w->obj;
			cam->gui_object_top++;
		}
		w = w->next;
	}
}
