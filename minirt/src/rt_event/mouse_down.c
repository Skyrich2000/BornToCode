#include "minirt.h"

#define GUI_CLICK_SIZE 10

static void	click_obj(int x, int y)
{
	int			i;
	t_camera	*cam;

	i = -1;
	cam = m()->curr_cam;
	while (++i < cam->gui_object_top)
	{
		if (x >= cam->gui_object[i].pos.x - GUI_CLICK_SIZE && \
			x <= cam->gui_object[i].pos.x + GUI_CLICK_SIZE && \
			y >= cam->gui_object[i].pos.y - GUI_CLICK_SIZE && \
			y <= cam->gui_object[i].pos.y + GUI_CLICK_SIZE)
		{
			cam->select_gui_object = cam->gui_object[i];
			return ;
		}
	}
	cam->select_gui_object.obj = 0;
}

int	mouse_down(int button, int x, int y, void *param)
{
	(void)param;
	click_obj(x, y);
	m()->scr.mouse_button = button;
	m()->scr.mouse_x = x;
	m()->scr.mouse_y = y;
	m()->scr.cam_start_pos = m()->curr_cam->pos;
	m()->scr.cam_start_dir = m()->curr_cam->dir;
	if (m()->curr_cam->select_gui_object.obj)
	{
		m()->scr.obj_start_pos = *get_object_pos(\
									m()->curr_cam->select_gui_object.obj, \
									m()->curr_cam->select_gui_object.type);
		m()->scr.obj_start_dir = get_object_dir(\
									m()->curr_cam->select_gui_object.obj, \
									m()->curr_cam->select_gui_object.type);
	}
	return (0);
}
