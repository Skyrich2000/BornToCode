#include "minirt.h"

static void	*render_block(void *data)
{
	const int		render_index = m()->curr_cam->render_index;
	const int		threads[2] = {(long long)data / W_THREAD, \
									(long long)data % W_THREAD};
	const int		size[2] = {
							(m()->scr.hei / H_THREAD), \
							(m()->scr.wid / W_THREAD)};
	int				i[2];

	i[0] = 0;
	while (i[0] <= size[0] / 4 + 2)
	{
		i[1] = 0;
		while (i[1] <= size[1])
		{
			render_pixel(m()->curr_cam, threads, size[0] / 4 * 0 + i[0], i[1]);
			render_pixel(m()->curr_cam, threads, size[0] / 4 * 1 + i[0], i[1]);
			render_pixel(m()->curr_cam, threads, size[0] / 4 * 2 + i[0], i[1]);
			render_pixel(m()->curr_cam, threads, size[0] / 4 * 3 + i[0], i[1]);
			if (m()->curr_cam->render_index != render_index)
				return (0);
			i[1] += m()->scr.lower_resolution + 1;
		}
		i[0] += m()->scr.lower_resolution + 1;
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
										m()->scr.wid, \
										m()->scr.hei);
		m()->curr_cam->img_addr = mlx_get_data_addr(\
										m()->curr_cam->img, \
										&m()->scr.bits_per_pixel, \
										&m()->scr.line_length, \
										&m()->scr.endian);
	}
	render_thread();
}
