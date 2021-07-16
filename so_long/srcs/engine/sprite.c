/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:16 by ycha              #+#    #+#             */
/*   Updated: 2021/07/16 07:49:17 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_sprite	*add_sprite(int offset_x, int offset_y, int img_speed)
{
	t_sprite *new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	new->imgs = create_list();
	if (!new->imgs)
		return (ERROR);
	new->subimg = 0;
	new->img_speed = img_speed;
	new->offset_x = offset_x;
	new->offset_y = offset_y;
	return (new);
}

int			add_sprite_subimage(t_sprite *spr, char *path)
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

void		change_sprite(t_instance *id, t_sprite *spr)
{
	if (id->spr == spr)
		return ;
	id->spr = spr;
	id->img_node = id->spr->imgs->next;
	id->img_speed = id->spr->img_speed;
}
