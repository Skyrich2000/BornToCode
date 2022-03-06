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
	if (keycode == 49)
	{
		mini->curr_cam = mini->curr_cam->next;
		draw(mini);
	}
	if (keycode == KEY_W)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_unit_(&mini->curr_cam->dir)), mini->curr_cam->dir, mini->curr_cam->fov);
		draw(mini);
	}
	if (keycode == KEY_S)
	{
		move_camera(mini->curr_cam, vec_add(mini->curr_cam->pos, vec_oppo(vec_unit_(&mini->curr_cam->dir))), mini->curr_cam->dir, mini->curr_cam->fov);
		draw(mini);
	}
	return (0);
}
