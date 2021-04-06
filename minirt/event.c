#include "minirt.h"

int exit_hook()
{
	exit(0);
}

// key event
int	key_hook(int keycode, t_window *window)
{
	if(keycode == 53)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit(0);
	}
	return (0);
}
