/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:16 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 03:03:40 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_sprite	*add_sprite(int offset_x, int offset_y, int img_speed, t_box mask)
{
	t_sprite *new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	if (!new)
		sl_exit(12);
	new->imgs = create_list();
	new->img_speed = img_speed;
	new->offset_x = offset_x;
	new->offset_y = offset_y;
	new->mask = mask;
	return (new);
}

t_background	*add_background(char *path, int x, int y)
{
	t_background *new;

	new = (t_background *)malloc(sizeof(t_background));
	if (!new)
		sl_exit(12);
	new->img = mlx_png_file_to_image(g()->mlx, path, &new->width, &new->height);
	if (!new->img)
	{
		free(new);
		return (ERROR);
	}
	new->x = x;
	new->y = y;
	return (new);
}

int			add_sprite_subimage(t_sprite *spr, char *path, int start, int end)
{
	char	*num;
	char	*str[2];
	void	*img;
	int		dir;

	dir = -1;
	if (start > end)
		dir = 1;
	start += dir;
	while (start != end)
	{
		num = sl_itoa(end);
		str[0] = sl_strjoin(path, num);
		str[1] = sl_strjoin(str[0], ".png");
		if (DEBUG)
			printf("LOAD: %s\n", str[1]);
		img = mlx_png_file_to_image(g()->mlx, str[1], &spr->width, &spr->height);
		if (!img)
			return (ERROR);
		push_list(spr->imgs, img);
		end += dir;
		free(str[0]);
		free(str[1]);
		free(num);
	}
	return (OK);
}

void		change_sprite(t_instance *id, t_sprite *spr)
{
	if (id->spr == spr)
		return ;
	id->spr = spr;
	id->img_node = id->spr->imgs->next;
}
