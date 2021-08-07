#include "engine.h"

t_font	*add_font(char *path, int size)
{
	t_font	*new;
	char	*str[3];
	int		temp[2];
	void	*img;
	int		i;

	new = (t_font *)malloc(sizeof(t_font));
	if (!new)
		sl_exit(12);
	i = -1;
	while (++i < 127)
	{
		str[0] = sl_itoa(i);
		str[1] = sl_strjoin(path, str[0]);
		str[2] = sl_strjoin(str[1], ".png");
		img = mlx_png_file_to_image(g()->mlx, str[2], &temp[0], &temp[1]);
		if (img)
		{
			new->real_size = temp[0];
			if (DEBUG)	// for debug
				printf("LOAD: %s\n", str[2]);
		}
		new->img[i] = img;
		free(str[0]);
		free(str[1]);
		free(str[2]);
	}
	new->size = size;
	return (new);
}

