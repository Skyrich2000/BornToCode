/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:08:47 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:08:51 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*render()
{
	const int		render_index = m()->curr_cam->render_index;
	int				i;
	int				j;

	i = 0;
	while (++i < m()->scr.hei)
	{
		j = 0;
		while (++j < m()->scr.wid)
		{
			render_pixel(i, j);
			if (m()->curr_cam->render_index != render_index)
				return (0);
		}
	}
	return (0);
}

void	draw(void)
{
	t_minirt	*g;

	g = m();
	if (!m()->curr_cam->img)
	{
		g->curr_cam->img = mlx_new_image(\
										g->scr.mlx, \
										g->scr.wid + 1, \
										g->scr.hei + 1);
		g->curr_cam->img_addr = mlx_get_data_addr(\
										g->curr_cam->img, \
										&g->scr.bits_per_pixel, \
										&g->scr.line_length, \
										&g->scr.endian);
	}
	m()->curr_cam->render_index++;
	render();
}
