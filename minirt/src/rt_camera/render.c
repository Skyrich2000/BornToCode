#include "minirt.h"

static void	*render_block(void *data)
{
	const int		render_index = m()->curr_cam->render_index;
	const int		thread_idx[2] = {(long long)data % W_THREAD, \
									(long long)data / W_THREAD};
	const int		block_size[2] = {m()->scr.wid / W_THREAD, \
									m()->scr.hei / H_THREAD};
	const int		size[2] = {
							(block_size[0]),
							(block_size[1] / 4) + (block_size[1] % 4) * (thread_idx[1] != (H_THREAD - 1))};
	int			x, y;
	int			start_x, start_y;
	int			end_x, end_y;

	start_x = thread_idx[0] * block_size[0];
	start_y = thread_idx[1] * block_size[1];
	end_x = start_x + size[0];
	end_y = start_y + size[1];
	if (end_x > m()->scr.wid)
		end_x = m()->scr.wid - m()->scr.lower_resolution;

	y = start_y;
	while (y < end_y)
	{
		x = start_x;
		while (x < end_x)
		{
			render_pixel(m()->curr_cam, x, y);
			render_pixel(m()->curr_cam, x, y + size[1] * 1);
			render_pixel(m()->curr_cam, x, y + size[1] * 2);
			render_pixel(m()->curr_cam, x, y + size[1] * 3);
			if (m()->curr_cam->render_index != render_index)
				return (0);
			x += m()->scr.lower_resolution + 1;
		}
		y += m()->scr.lower_resolution + 1;
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
	if (!m()->curr_cam->img)
	{
		m()->curr_cam->img = mlx_new_image(\
										m()->scr.mlx, \
										m()->scr.wid + 1, \
										m()->scr.hei + 1);
		m()->curr_cam->img_addr = mlx_get_data_addr(\
										m()->curr_cam->img, \
										&m()->scr.bits_per_pixel, \
										&m()->scr.line_length, \
										&m()->scr.endian);
	}
	render_thread();
}
