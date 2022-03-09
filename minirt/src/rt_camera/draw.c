#include "minirt.h"

static void	*render(void *data)
{
	const t_camera	*cam = m()->curr_cam;
	const int		render_index = cam->render_index;
	const int		thread_idx[2] = {(long long)data / W_THREAD, \
									(long long)data % W_THREAD};
	const int		size[2] = {
							(m()->scr.hei / H_THREAD), \
							(m()->scr.wid / W_THREAD)};
	int				idx[2];

	idx[0] = 0;
	while (++idx[0] <= size[0] / 4 + 2)
	{
		idx[1] = 0;
		while (++idx[1] <= size[1])
		{
			render_pixel(cam, thread_idx, size[0] / 4 * 0 + idx[0], idx[1]);
			render_pixel(cam, thread_idx, size[0] / 4 * 1 + idx[0], idx[1]);
			render_pixel(cam, thread_idx, size[0] / 4 * 2 + idx[0], idx[1]);
			render_pixel(cam, thread_idx, size[0] / 4 * 3 + idx[0], idx[1]);
			if (cam->render_index != render_index)
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
