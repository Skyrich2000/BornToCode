#include "minirt.h"

static void	move_camera_dir(t_vec dir, double diff_x, double diff_y)
{
	dir = vec_add(dir, \
		vec_muln(vec_unit_(&m()->curr_cam->hor), diff_x / m()->scr.wid * 2));
	dir = vec_add(dir, \
		vec_muln(vec_unit_(&m()->curr_cam->ver), -diff_y / m()->scr.hei * 2));
	dir = vec_unit(dir);
	set_camera(m()->curr_cam, m()->curr_cam->pos, dir, m()->curr_cam->fov);
	m()->render_refresh = 1;
}

static void	move_object_pos(t_vec pos, double diff_x, double diff_y)
{
	pos = vec_add(pos, \
		vec_muln(vec_unit_(&m()->curr_cam->hor), diff_x / m()->scr.wid * 20));
	pos = vec_add(pos, \
		vec_muln(vec_unit_(&m()->curr_cam->ver), -diff_y / m()->scr.hei * 20));
	set_object_pos(m()->curr_cam->select_gui_object.obj, \
				m()->curr_cam->select_gui_object.type, pos);
	m()->render_refresh = 1;
}

static void	move_object_dir(t_vec pos, double diff_x, double diff_y)
{
	t_vec	diff;

	diff = vec_muln(vec_unit_(&m()->curr_cam->hor), diff_x / m()->scr.wid * 2);
	diff = vec_add(diff, \
		vec_muln(vec_unit_(&m()->curr_cam->ver), -diff_y / m()->scr.hei * 2));
	set_object_dir(m()->curr_cam->select_gui_object.obj, \
				m()->curr_cam->select_gui_object.type, pos, diff);
	m()->render_refresh = 1;
}

int	mouse_up(int button, int x, int y, void *param)
{
	m()->curr_cam->select_gui_object.obj = 0;
	m()->scr.mouse_x = -1;
	m()->scr.mouse_y = -1;
	return (0);
}

int	mouse_move(int x, int y, void *param)
{
	int		diff_x;
	int		diff_y;

	if (m()->scr.mouse_x == -1 || m()->scr.mouse_y == -1)
		return (0);
	diff_x = x - m()->scr.mouse_x;
	diff_y = y - m()->scr.mouse_y;
	if (m()->curr_cam->select_gui_object.obj)
	{
		if (m()->scr.mouse_button == 1)
			move_object_pos(m()->scr.obj_start_pos, diff_x, diff_y);
		else
			move_object_dir(m()->scr.obj_start_dir, diff_x, diff_y);
	}
	else
		move_camera_dir(m()->scr.cam_start_dir, diff_x, diff_y);
	return (0);
}
