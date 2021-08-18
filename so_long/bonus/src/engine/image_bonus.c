/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:28:10 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:28:10 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine_bonus.h"
#include "engine/engine_image_bonus.h"

t_sprite	*add_sprite(int offset_x, int offset_y, int img_speed, t_box mask)
{
	t_sprite	*new;

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
	t_background	*new;

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

int	add_sprite_subimage(t_sprite *spr, char *path, int start, int end)
{
	char	*str[3];
	void	*img;
	int		dir;

	dir = -1;
	if (start > end)
		dir = 1;
	start += dir;
	while (start != end)
	{
		str[0] = sl_itoa(end);
		str[1] = sl_strjoin(path, str[0]);
		str[2] = sl_strjoin(str[1], ".png");
		DEBUG && printf("LOAD: %s\n", str[2]);
		img = mlx_png_file_to_image(g()->mlx, str[2], \
									&spr->width, &spr->height);
		if (!img)
			return (ERROR);
		push_list(spr->imgs, img);
		end += dir;
		sl_free_arr3(str);
	}
	return (OK);
}

void	change_sprite(t_instance *id, t_sprite *spr)
{
	if (id->spr == spr)
		return ;
	id->spr = spr;
	id->img_node = id->spr->imgs->next;
}
