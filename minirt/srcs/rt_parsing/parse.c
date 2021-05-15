#include "minirt.h"

static void	parser_init(int (*parser[9])(char **, t_minirt *))
{
	parser[r] = parse_r;
	// parser[a] = parse_a;
	parser[c] = parse_c;
	parser[l] = parse_l;
	parser[sp] = parse_sp;
	parser[pl] = parse_pl;
	// parser[sq] = parse_sq;
	// parser[cy] = parse_cy;
	// parser[tr] = parse_tr;
}

static int	parsing(t_minirt *mini, char *str)
{
	int		i;
	int		(*parser[9])(char **, t_minirt *);
	char	**data;
	char	**line;

	parser_init(parser);
	data = ft_split(str, "\n");
	while (*data)
	{
		line = ft_split(*data, WHITESPACE);
		i = -1;
		while (++i < 9)
			if (!ft_strncmp(line[0], \
							(char [9][3]){"R", "A", "c", "l", "sp", "pl" \
										, "sq", "cy", "tr"}[i]) && \
				parser[i](line, mini))
				break ;
		ft_free_split(line, ft_arrsize(line));
		if (i == 9)
			return (printf_error());
		++data;
	}
	return (OK);
}

static int	fileread(char *file, t_minirt *mini, char *line)
{
	char	ch[1];
	int		s;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	s = ft_strlen(file);
	if (fd < 0 || s < 3 || file[s - 1] != 't' || file[s - 2] != 'r' || file[s - 3] != '.')
		return (ERROR);
	s = read(fd, &ch, 1);
	while (s > 0)
	{
		line[i++] = ch[0];
		s = read(fd, &ch, 1);
	}
	return (s >= 0);
}

int	input(int argc, char **argv, t_minirt *mini)
{
	char line[4400000];

	return (argc == 2 && \
			fileread(argv[1], mini, line) && \
			parsing(mini, line));
}
