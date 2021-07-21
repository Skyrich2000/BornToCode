#include "engine.h"

// TODO: free before error return
t_font	*add_font(char *path)
{
	t_font	*new;
	char	*num;
	char	*path_all[2];
	void	*img;
	int		i;

	new = (t_font *)malloc(sizeof(t_font));
	if (!new)
		return (ERROR);
	i = -1;
	while (++i <= 127)
	{
		num = sl_itoa(i);
		path_all[0] = sl_strjoin(path, num);
		path_all[1] = sl_strjoin(path_all[0], ".xpm");
		img = mlx_xpm_file_to_image(g()->mlx, path_all[1], &new->width, &new->height);
		if (DEBUG && img)	// for debug
			printf("LOAD: %s\n", path_all[1]);
		new->img[i] = img;
		free(path_all[0]);
		free(path_all[1]);
		free(num);
	}
	return (new);
}
