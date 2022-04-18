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

static void	*render(void *data)
{
	const int		render_index = m()->curr_cam->render_index;
	const int		thread_idx[2] = {(long long)data / W_THREAD, \
									(long long)data % W_THREAD};
	const int		size[2] = {\
							(m()->scr.hei / H_THREAD), \
							(m()->scr.wid / W_THREAD)};
	int				idx[2];

	idx[0] = 0;
	while (++idx[0] <= size[0] / 4 + size[0] % 4)
	{
		idx[1] = 0;
		while (++idx[1] <= size[1])
		{
			render_pixel(thread_idx, size[0] / 4 * 0 + idx[0], idx[1]);
			render_pixel(thread_idx, size[0] / 4 * 1 + idx[0], idx[1]);
			render_pixel(thread_idx, size[0] / 4 * 2 + idx[0], idx[1]);
			render_pixel(thread_idx, size[0] / 4 * 3 + idx[0], idx[1]);
			if (m()->curr_cam->render_index != render_index)
				return (0);
		}
	}
	return (0);
}

static int	render_thread(void)
{
	pthread_t		thread;
	int				i;

	i = -1;
	m()->curr_cam->render_index++;
	while (++i < H_THREAD * W_THREAD)
	{
		pthread_create(&thread, NULL, render, (void *)(long long)i);
		pthread_detach(thread);
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
	render_thread();
}
