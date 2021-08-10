/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:02 by ycha              #+#    #+#             */
/*   Updated: 2021/08/10 18:23:52 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_img(void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(g()->mlx, g()->win, img, \
						x - g()->view.view_xview, y - g()->view.view_yview);
}

void	draw_background(t_background *back)
{
	draw_img(back->img, back->x, back->y);
}

void	draw_sprite(t_sprite *spr, t_list *img_node, int x, int y)
{
	if (spr && img_node && img_node->data)
		draw_img(img_node->data, x - spr->offset_x, y - spr->offset_y);
}

void	draw_self(t_instance *this)
{
	draw_sprite(this->spr, this->img_node, this->x, this->y);
}

void	draw_text(t_font *font, char *str, int pos[2], float align[2])
{
	int		x;
	int		y;
	int		correction;
	int		i;

	i = -1;
	correction = -font->real_size / 2 + font->size / 2;
	x = pos[0] - font->size * sl_strlen(str) * align[0];
	y = pos[1] - font->size * align[1];
	while (str[++i])
		draw_img(font->img[(int)str[i]], \
						x + correction + font->size * i, y + correction);
}
