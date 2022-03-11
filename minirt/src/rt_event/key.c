#include "minirt.h"

int	exit_hook(void)
{
	exit(0);
}

static void	move_object(t_camera *cam, t_vec diff)
{
	t_gui_object	*gui;
	t_vec			*pos;

	if (cam->select_gui_object.obj && m()->scr.mouse_button != 2)
	{
		gui = &cam->select_gui_object;
		m()->scr.obj_start_pos = vec_add(m()->scr.obj_start_pos, diff);
		pos = get_object_pos(gui->obj, gui->type);
		set_object_pos(gui->obj, gui->type, vec_add(*pos, diff));
	}
}

void	key_camera_move(void)
{
	t_vec			diff;
	t_gui_object	*gui;
	t_camera		*cam;

	cam = m()->curr_cam;
	if (m()->keys[KEY_W])
		diff = vec_unit_(&cam->dir);
	if (m()->keys[KEY_S])
		diff = vec_oppo(vec_unit_(&cam->dir));
	if (m()->keys[KEY_D])
		diff = vec_unit_(&cam->hor);
	if (m()->keys[KEY_A])
		diff = vec_oppo(vec_unit_(&cam->hor));
	if (m()->keys[KEY_SPACEBAR])
		diff = vec_unit_(&cam->ver);
	if (m()->keys[KEY_LEFT_SHIFT])
		diff = vec_oppo(vec_unit_(&cam->ver));
	if (m()->keys[KEY_W] || m()->keys[KEY_S] || m()->keys[KEY_D] || \
		m()->keys[KEY_A] || m()->keys[KEY_SPACEBAR] || \
		m()->keys[KEY_LEFT_SHIFT])
	{
		set_camera(cam, vec_add(cam->pos, diff), cam->dir, cam->fov);
		move_object(cam, diff);
		m()->render_refresh += 1;
	}
}

int	key_up(int keycode)
{
	if (keycode == 53)
		exit(0);
	if (keycode == KEY_G)
	{
		m()->gui_toggle = !m()->gui_toggle;
		return (0);
	}
	if (keycode == KEY_C)
		m()->curr_cam = m()->curr_cam->next;
	else if (keycode == KEY_R)
	{
		m()->resolution_toggle = !m()->resolution_toggle;
		m()->scr.lower_resolution = LOWER_RESOLUTION * !m()->resolution_toggle;
	}
	else if (keycode == KEY_PLUS)
		m()->scr.anti += 5;
	else if (keycode == KEY_MINUS)
		m()->scr.anti = ft_max(0, m()->scr.anti - 5);
	else if (keycode == KEY_L)
		m()->light_toggle = !m()->light_toggle;
	else if (keycode == KEY_M)
		m()->ray_mode = !m()->ray_mode;
	m()->keys[keycode] = 0;
	m()->render_refresh = 1;
	return (0);
}

int	key_down(int keycode)
{
	m()->keys[keycode] = 1;
	return (0);
}
