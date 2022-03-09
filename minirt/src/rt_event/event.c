#include "minirt.h"

int	exit_hook(void)
{
	exit(0);
}

static void	key_camera_updown(int keycode)
{
	if (keycode == KEY_SPACEBAR)
		set_camera(m()->curr_cam, \
					vec_add(m()->curr_cam->pos, \
					vec_unit_(&m()->curr_cam->ver)), \
					m()->curr_cam->dir, m()->curr_cam->fov);
	if (keycode == KEY_LEFT_SHIFT)
		set_camera(m()->curr_cam, \
					vec_add(m()->curr_cam->pos, \
					vec_oppo(vec_unit_(&m()->curr_cam->ver))), \
					m()->curr_cam->dir, m()->curr_cam->fov);
}

static void	key_camera_move(int keycode)
{
	if (keycode == KEY_W)
		set_camera(m()->curr_cam, \
					vec_add(m()->curr_cam->pos, \
					vec_unit_(&m()->curr_cam->dir)), \
					m()->curr_cam->dir, m()->curr_cam->fov);
	if (keycode == KEY_S)
		set_camera(m()->curr_cam, \
					vec_add(m()->curr_cam->pos, \
					vec_oppo(vec_unit_(&m()->curr_cam->dir))), \
					m()->curr_cam->dir, m()->curr_cam->fov);
	if (keycode == KEY_D)
		set_camera(m()->curr_cam, \
					vec_add(m()->curr_cam->pos, \
					vec_unit_(&m()->curr_cam->hor)), \
					m()->curr_cam->dir, m()->curr_cam->fov);
	if (keycode == KEY_A)
		set_camera(m()->curr_cam, \
					vec_add(m()->curr_cam->pos, \
					vec_oppo(vec_unit_(&m()->curr_cam->hor))), \
					m()->curr_cam->dir, m()->curr_cam->fov);
}

static void	key_camera_dir(int keycode)
{
	if (keycode == KEY_UP)
		set_camera(m()->curr_cam, \
					m()->curr_cam->pos, \
					vec_unit(vec_add(m()->curr_cam->dir, \
					vec_muln(vec_unit_(&m()->curr_cam->ver), 0.1))), \
					m()->curr_cam->fov);
	if (keycode == KEY_DOWN)
		set_camera(m()->curr_cam, \
					m()->curr_cam->pos, \
					vec_unit(vec_add(m()->curr_cam->dir, \
					vec_muln(vec_unit_(&m()->curr_cam->ver), -0.1))), \
					m()->curr_cam->fov);
	if (keycode == KEY_RIGHT)
		set_camera(m()->curr_cam, \
					m()->curr_cam->pos, \
					vec_unit(vec_add(m()->curr_cam->dir, \
					vec_muln(vec_unit_(&m()->curr_cam->hor), 0.1))), \
					m()->curr_cam->fov);
	if (keycode == KEY_LEFT)
		set_camera(m()->curr_cam, \
					m()->curr_cam->pos, \
					vec_unit(vec_add(m()->curr_cam->dir, \
					vec_muln(vec_unit_(&m()->curr_cam->hor), -0.1))), \
					m()->curr_cam->fov);
}

int	key_hook(int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(m()->scr.mlx, m()->scr.win);
		exit(0);
		return (0);
	}
	if (keycode == KEY_C)
	{
		m()->curr_cam = m()->curr_cam->next;
	}
	if (keycode == KEY_L)
	{
		m()->light_toggle = !m()->light_toggle;
		m()->scr.anti = 0;
		if (m()->light_toggle)
			m()->scr.anti = ANTI_ALIASING;
	}
	key_camera_dir(keycode);
	key_camera_move(keycode);
	key_camera_updown(keycode);
	draw();
	return (0);
}
