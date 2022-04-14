/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:53:54 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:53:55 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define X 0
#define Y 1

static void	set_var(void *data, int size[2], int start[2], int end[2])
{
	int		thread_idx[2];
	int		block_size[2];

	thread_idx[X] = (long long)data % W_THREAD;
	thread_idx[Y] = (long long)data / W_THREAD;
	block_size[X] = m()->scr.wid / W_THREAD;
	block_size[Y] = m()->scr.hei / H_THREAD;
	size[X] = block_size[X];
	size[Y] = block_size[Y] / 4;
	size[Y] += (block_size[Y] % 4) * (thread_idx[Y] != (H_THREAD - 1));
	start[X] = thread_idx[X] * block_size[X];
	start[Y] = thread_idx[Y] * block_size[Y];
	end[X] = start[X] + size[X];
	end[Y] = start[Y] + size[Y];
	if (end[X] > m()->scr.wid)
		end[X] = m()->scr.wid - m()->scr.lower_resolution;
}

static void	*render_block(void *data)
{
	const int	render_index = m()->curr_cam->render_index;
	int			size[2];
	int			start[2];
	int			end[2];
	int			i[2];

	set_var(data, size, start, end);
	i[Y] = start[Y];
	while (i[Y] < end[Y])
	{
		i[X] = start[X];
		while (i[X] < end[X])
		{
			render_pixel(m()->curr_cam, i[X], i[Y]);
			render_pixel(m()->curr_cam, i[X], i[Y] + size[Y] * 1);
			render_pixel(m()->curr_cam, i[X], i[Y] + size[Y] * 2);
			render_pixel(m()->curr_cam, i[X], i[Y] + size[Y] * 3);
			if (m()->curr_cam->render_index != render_index)
				return (0);
			i[X] += m()->scr.lower_resolution + 1;
		}
		i[Y] += m()->scr.lower_resolution + 1;
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
		pthread_create(&thread, NULL, render_block, (void *)(long long)i);
		pthread_detach(thread);
	}
	return (0);
}

void	render(void)
{
	t_minirt	*g;

	g = m();
	if (!g->curr_cam->img)
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
