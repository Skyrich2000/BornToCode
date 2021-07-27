/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:02 by ycha              #+#    #+#             */
/*   Updated: 2021/07/28 04:53:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_background(t_background *back)
{
	mlx_put_image_to_window(g()->mlx, g()->win, back->img, back->x - g()->view.view_xview, back->y - g()->view.view_yview);
}

void	draw_line(int pos[2], int dir[2], int len, int color)
{
	while (len--)
		mlx_pixel_put(g()->mlx, g()-> win, pos[0] + dir[0] * len -g()->view.view_xview, pos[1] + dir[1] * len -g()->view.view_yview, color);
}

void	draw_box(t_box	box, int color)
{
	draw_line((int[2]){box.x1, box.y1}, (int[2]){1, 0}, box.x2 - box.x1, color);
	draw_line((int[2]){box.x1, box.y2}, (int[2]){1, 0}, box.x2 - box.x1, color);
	draw_line((int[2]){box.x1, box.y1}, (int[2]){0, 1}, box.y2 - box.y1, color);
	draw_line((int[2]){box.x2, box.y1}, (int[2]){0, 1}, box.y2 - box.y1, color);
}

void	draw_point(int x, int y, int color)
{
	draw_box((t_box){x - 1, y - 1, x + 1, y + 1}, color);
	mlx_pixel_put(g()->mlx, g()->win, x - g()->view.view_xview, y - g()->view.view_yview, color);
}

void	draw_img(void *img, int x, int y)
{
	if (img)
		mlx_put_image_to_window(g()->mlx, g()->win, img, x - g()->view.view_xview, y-g()->view.view_yview);
}

void	draw_sprite(t_sprite *spr, t_list *img_node, int x, int y)
{
	if (spr && img_node && img_node->data)
		mlx_put_image_to_window(g()->mlx, g()->win, img_node->data, x - spr->offset_x - g()->view.view_xview, y - spr->offset_y - g()->view.view_yview);
}

void	draw_debug()
{
	int i;
	t_list *node;
	t_instance *ins;

	i = -1;
	while (++i < OBJ_SIZE)
	{
		node = g()->instances[i]->next;
		while (node)
		{
			ins = (t_instance *)node->data;
			node = node->next;
			draw_box((t_box){ ins->x - ins->spr->offset_x + ins->spr->mask.x1,
							  ins->y - ins->spr->offset_y + ins->spr->mask.y1,
							  ins->x - ins->spr->offset_x + ins->spr->mask.x2,
							  ins->y - ins->spr->offset_y + ins->spr->mask.y2 }, C_GREEN);
			draw_point(ins->x, ins->y, C_RED);
			draw_point(ins->x - ins->spr->offset_x, ins->y - ins->spr->offset_x, C_YELLOW);
		}
	}
}

int		draw_text(t_font *font, char *str, int pos[2], float align[2])
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
	{
		draw_img(font->img[(int)str[i]], x + correction + font->size * i, y + correction);
	}
	return (y + font->size / 2);
}
