#include "minirt.h"

int	exit_hook(void)
{
	exit(0);
}

int	key_hook(int keycode, t_minirt *mini)
{
	if (keycode == 53)
	{
		mlx_destroy_window(mini->scr.mlx, mini->scr.win);
		exit(0);
		return (0);
	}
	if (keycode == KEY_C)
	{
		mini->curr_cam = mini->curr_cam->next;
	}
	if (keycode == KEY_W)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_unit_(&mini->curr_cam->dir)), mini->curr_cam->dir, mini->curr_cam->fov);
	}
	if (keycode == KEY_S)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_oppo(vec_unit_(&mini->curr_cam->dir))), mini->curr_cam->dir, mini->curr_cam->fov);
	}
	if (keycode == KEY_D)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_unit_(&mini->curr_cam->hor)), mini->curr_cam->dir, mini->curr_cam->fov);
	}
	if (keycode == KEY_A)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_oppo(vec_unit_(&mini->curr_cam->hor))), mini->curr_cam->dir, mini->curr_cam->fov);
	}
	if (keycode == KEY_SPACEBAR)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_unit_(&mini->curr_cam->ver)), mini->curr_cam->dir, mini->curr_cam->fov);
	}
	if (keycode == KEY_LEFT_SHIFT)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_oppo(vec_unit_(&mini->curr_cam->ver))), mini->curr_cam->dir, mini->curr_cam->fov);
	}
	if (keycode == KEY_UP)
	{
		move_camera(mini->curr_cam, mini->curr_cam->pos, vec_unit(vec_add(mini->curr_cam->dir, vec_muln(vec_unit_(&mini->curr_cam->ver), 0.1))), mini->curr_cam->fov);
	}
	if (keycode == KEY_DOWN)
	{
		move_camera(mini->curr_cam, mini->curr_cam->pos, vec_unit(vec_add(mini->curr_cam->dir, vec_muln(vec_unit_(&mini->curr_cam->ver), -0.1))), mini->curr_cam->fov);
	}
	if (keycode == KEY_RIGHT)
	{
		move_camera(mini->curr_cam, mini->curr_cam->pos, vec_unit(vec_add(mini->curr_cam->dir, vec_muln(vec_unit_(&mini->curr_cam->hor), 0.1))), mini->curr_cam->fov);
	}
	if (keycode == KEY_LEFT)
	{
		move_camera(mini->curr_cam, mini->curr_cam->pos, vec_unit(vec_add(mini->curr_cam->dir, vec_muln(vec_unit_(&mini->curr_cam->hor), -0.1))), mini->curr_cam->fov);
	}
	if (keycode == KEY_L)
	{
		mini->light_toggle = !mini->light_toggle;
		mini->scr.anti = 0;
		if (mini->light_toggle)
			mini->scr.anti = ANTI_ALIASING;
		
	}
	draw(mini);
	return (0);
}
