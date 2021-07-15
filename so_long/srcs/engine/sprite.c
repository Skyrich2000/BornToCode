#include "engine.h"

t_sprite	*create_sprite()
{
	t_sprite *new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	new->imgs = create_list();
	if (!new->imgs)
		return (ERROR);
	new->offset_x = 0;
	new->offset_y = 0;
	return (new);
}

int			add_subimage(t_sprite *spr, char *path)
{
	void	*img;

	spr->subimg++;
	img = mlx_xpm_file_to_image(g()->mlx, path, &spr->width, &spr->height);
	return (push_list(spr->imgs, img));
}

void		delete_sprite(t_sprite *spr)
{
	free_list(spr->imgs, 0);
	free(spr);
}
