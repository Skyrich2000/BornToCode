/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:02 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 03:27:51 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_point(int x, int y, int color)
{
	if (x >= 0 && y >= 0)
		mlx_pixel_put(g()->mlx, g()-> win, x, y, color);
}

void	draw_line(int pos[2], int dir[2], int len, int color)
{
	while (len--)
		draw_point(pos[0] + dir[0] * len - g()->view.view_xview, \
				   pos[1] + dir[1] * len - g()->view.view_yview, color);
}

void	draw_box(t_box	box, int clr)
{
	draw_line((int [2]){box.x1, box.y1}, (int [2]){1, 0}, box.x2 - box.x1, clr);
	draw_line((int [2]){box.x1, box.y2}, (int [2]){1, 0}, box.x2 - box.x1, clr);
	draw_line((int [2]){box.x1, box.y1}, (int [2]){0, 1}, box.y2 - box.y1, clr);
	draw_line((int [2]){box.x2, box.y1}, (int [2]){0, 1}, box.y2 - box.y1, clr);
}

void	draw_bold_point(int x, int y, int color)
{
	draw_box((t_box){x - 1, y - 1, x + 1, y + 1}, color);
	draw_point(x - g()->view.view_xview, y - g()->view.view_yview, color);
}

void	draw_debug(void)
{
	int			i;
	t_list		*node;
	t_instance	*ins;

	i = -1;
	while (++i < OBJ_SIZE)
	{
		node = g()->instances[i]->next;
		while (node)
		{
			ins = (t_instance *)node->data;
			node = node->next;
			draw_box((t_box){ins->x - ins->spr->offset_x + ins->spr->mask.x1, \
							 ins->y - ins->spr->offset_y + ins->spr->mask.y1, \
							 ins->x - ins->spr->offset_x + ins->spr->mask.x2, \
							 ins->y - ins->spr->offset_y + ins->spr->mask.y2}, \
							 C_GREEN);
			draw_bold_point(ins->x, ins->y, C_RED);
			draw_bold_point(ins->x - ins->spr->offset_x, ins->y - \
							ins->spr->offset_x, C_YELLOW);
		}
	}
}
