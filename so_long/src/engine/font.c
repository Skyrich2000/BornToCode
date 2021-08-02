#include "engine.h"

t_font	*add_font(char *path, int size)
{
	t_font	*new;
	char	*path_all[3];
	int		temp[2];
	void	*img;
	int		i;

	new = (t_font *)malloc(sizeof(t_font));
	if (!new)
		sl_exit(12);
	i = -1;
	while (++i < 127)
	{
		path_all[0] = sl_itoa(i);
		path_all[1] = sl_strjoin(path, path_all[0]);
		path_all[2] = sl_strjoin(path_all[1], ".png");
		img = mlx_png_file_to_image(g()->mlx, path_all[2], &temp[0], &temp[1]);
		if (img)
		{
			new->real_size = temp[0];
			if (DEBUG)	// for debug
				printf("LOAD: %s\n", path_all[2]);
		}
		new->img[i] = img;
		free(path_all[0]);
		free(path_all[1]);
		free(path_all[2]);
	}
	new->size = size;
	return (new);
}

