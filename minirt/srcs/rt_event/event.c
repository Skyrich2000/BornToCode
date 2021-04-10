#include "event.h"
#include <stdio.h>
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
	printf("[keycode = %d]\n", keycode);
	return (0);
}

