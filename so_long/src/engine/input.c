#include "engine.h"

static int	check_file_name(char *fname)
{
	int		len;

	len = sl_strlen(fname);
	if (len < 4 || \
		fname[len - 4] != '.' || \
		fname[len - 3] != 'b' || \
		fname[len - 2] != 'e' || \
		fname[len - 1] != 'r')
		return (ERROR);
	return (OK);
}

static int check_map_char(int width, int height)
{
	int i;
	int j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (!ft_strchr("10PEC", g()->ber[i][j]))
				return (ERROR);
		}
	}
	return (OK);
}

static int check_map_objects(int width, int height)
{
	int i;
	int j;
	int e_num;
	int c_num;
	int p_num;

	e_num = 0;
	c_num = 0;
	p_num = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			if (g()->ber[i][j] == 'P')
				p_num++;
			else if (g()->ber[i][j] == 'E')
				e_num++;
			else if (g()->ber[i][j] == 'C')
				c_num++;
		}
	}
	if (p_num >= 1 && e_num >= 1 && c_num >= 1)
		return (OK);
	return (ERROR);
}

static int check_map_closed(int width, int height)
{
	int i;

	i = -1;
	while (++i < height)
	{
		if (g()->ber[i][0] != '1' || g()->ber[i][width - 1] != '1')
			return (ERROR);
	}
	i = -1;
	while (++i < width)
	{
		if (g()->ber[0][i] != '1' || g()->ber[height - 1][i] != '1')
			return (ERROR);
	}
	return (OK);
}

static int check_map_rectangular(int width, int height)
{
	int i;

	i = -1;
	while (++i < height)
	{
		if (sl_strlen(g()->ber[i]) != width)
			return (ERROR);
	}
	return (OK);
}

int		init_input(int ac, char **av)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	int		width;
	int		height;

	if (ac != 2 || !check_file_name(av[1]))
		return (ERROR);
	sl_bzero(buf, BUFFER_SIZE);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || read(fd, &buf, BUFFER_SIZE) == -1)
		return (ERROR);
	g()->ber = sl_split(buf, '\n');
	width = sl_strlen(g()->ber[0]);
	height = sl_split_size(g()->ber);
	if (check_map_rectangular(width, height) && \
		check_map_char(width, height) && \
		check_map_closed(width, height) && \
		check_map_objects(width, height))
		return (OK);
	close(fd);
	return (ERROR);
}