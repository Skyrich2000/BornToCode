#include "minirt.h"

#define GUI_CLICK_SIZE 10

static void	set_selected_obj(int x, int y)
{
	int				i;
	t_camera	*cam;

	i = -1;
	cam = m()->curr_cam;
	if (cam->select_gui_object.obj)
	{
		while (++i < cam->gui_button_top)
		{
			if (x >= cam->gui_button[i].pos.x - GUI_CLICK_SIZE && \
				x <= cam->gui_button[i].pos.x + GUI_CLICK_SIZE && \
				y >= cam->gui_button[i].pos.y - GUI_CLICK_SIZE && \
				y <= cam->gui_button[i].pos.y + GUI_CLICK_SIZE)
			{
				cam->gui_button[i].f(&cam->select_gui_object);
				break;
			}
		}
		cam->select_gui_object.obj = 0;
		set_gui_objects(cam);
		draw();
		return ;
	}
	while (++i < cam->gui_object_top)
	{
		if (x >= cam->gui_object[i].pos.x - GUI_CLICK_SIZE && \
			x <= cam->gui_object[i].pos.x + GUI_CLICK_SIZE && \
			y >= cam->gui_object[i].pos.y - GUI_CLICK_SIZE && \
			y <= cam->gui_object[i].pos.y + GUI_CLICK_SIZE)
		{
			cam->select_gui_object = cam->gui_object[i];
			set_gui_button(cam);
			return ;
		}
	}
}

static void	move_camera_dir(t_vec dir, double diff_x, double diff_y)
{
	dir = vec_add(dir, \
		vec_muln(vec_unit_(&m()->curr_cam->hor), diff_x / m()->scr.wid * 2));
	dir = vec_add(dir, \
		vec_muln(vec_unit_(&m()->curr_cam->ver), -diff_y / m()->scr.hei * 2));
	dir = vec_unit(dir);
	set_camera(m()->curr_cam, m()->curr_cam->pos, dir, m()->curr_cam->fov);
	draw();
}

int	mouse_up(int button, int x, int y, void *param)
{
	int		diff_x;
	int		diff_y;

	if (button != 1)
		return (0);
	diff_x = x - m()->scr.mouse_x;
	diff_y = y - m()->scr.mouse_y;
	if (diff_x > -10 && diff_x < 10 && diff_y > -10 && diff_y < 10)
		set_selected_obj(x, y);
	// else
		// move_camera_dir(m()->curr_cam->dir, diff_x, diff_y);
	m()->scr.mouse_x = -1;
	m()->scr.mouse_y = -1;
	return (0);
}

int mouse_move(int x, int y, void *param)
{
	int		diff_x;
	int		diff_y;

	if (m()->scr.mouse_x == -1 || m()->scr.mouse_y == -1)
		return (0);
	diff_x = x - m()->scr.mouse_x;
	diff_y = y - m()->scr.mouse_y;
	move_camera_dir(m()->scr.start_dir, diff_x, diff_y);
	return (0);
}

int	mouse_down(int button, int x, int y, void *param)
{
	if (button != 1)
		return (0);
	m()->scr.mouse_x = x;
	m()->scr.mouse_y = y;
	m()->scr.start_dir = m()->curr_cam->dir;
	return (0);
}
