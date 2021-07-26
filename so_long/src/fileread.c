#include "engine.h"

int check_map(char **map)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{

		}
	}
	return(OK);
}

int init_map(char **argv)
{
	char	*line;
	char	**map;
	int		idx;

	idx - 1;
	while (argv[++idx])
	{
		line = malloc(BUFFER_SIZE);
		if (!line)
			exit(1);
		fileread(argv[idx], &line);
		map = sl_split(line, '\n'); // add list
		// g()->map
		free(line);
		sl_free_split(map); // 필요 할 듯
	}
}

int	fileread(char *fname, char **line)
{
	char	ch;
	int		len;
	int		fd;
	int		i;

	i = 0;
	len = sl_strlen(fname);
	if (fd < 0 || len < 4 || \
		fname[len - 4] != '.' || \
		fname[len - 3] != 'b' || \
		fname[len - 2] != 'e' || \
		fname[len - 1] != 'r')
		return (ERROR);
	fd = open(fname, O_RDONLY);
	while (read(fd, &ch, 1) > 0)
	{
		(*line)[i++] = ch;
	}
	return (OK);
}
