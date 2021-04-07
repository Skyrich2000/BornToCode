#include "event.h"

int exit_hook()
{
	exit(0);
}

// key event
int	key_hook(int keycode, t_screen *screen)
{
	if(keycode == 53)
	{
		mlx_destroy_window(screen->mlx, screen->win);
		exit(0);
	}
	return (0);
}

