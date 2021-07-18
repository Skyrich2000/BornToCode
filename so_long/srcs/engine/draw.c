/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:02 by ycha              #+#    #+#             */
/*   Updated: 2021/07/16 07:49:03 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	draw_background(t_canvas *background)
{
	mlx_put_image_to_window(g()->mlx, g()->win, background->img, 0, 0);
}

void	draw_subimg(void *img, int x, int y)
{
	mlx_put_image_to_window(g()->mlx, g()->win, img, x, y);
}

void	draw_sprite(t_sprite *spr, t_list *img_node, int x, int y)
{
	if (img_node)
		mlx_put_image_to_window(g()->mlx, g()->win, img_node->data, x - spr->offset_x, y - spr->offset_y);
}
