/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:52:46 by ycha              #+#    #+#             */
/*   Updated: 2022/03/06 23:34:31 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define KEY_NUM 9

static void	parser_init(int (*parser[9])(char **))
{
	parser[r] = parse_r;
	parser[a] = parse_a;
	parser[c] = parse_c;
	parser[l] = parse_l;
	parser[sp] = parse_sp;
	parser[pl] = parse_pl;
	parser[sq] = parse_sq;
	parser[cy] = parse_cy;
	parser[tr] = parse_tr;
}

static int	find_key_index(char *key)
{
	int	j;

	j = -1;
	while (++j < KEY_NUM)
	{
		if (ft_strncmp(key, (char [9][3]){
			"R", "A", "c", "l", "sp", "pl", "sq", "cy", "tr" }[j]) == 0)
			break ;
	}
	return (j);
}

static int	parsing(char *file_data)
{
	int		i;
	int		key_index;
	int		(*parser[9])(char **);
	char	**lines;
	char	**words;

	i = -1;
	parser_init(parser);
	lines = ft_split(file_data, "\n");
	while (lines[++i])
	{
		if (lines[i][0] == '#')
			continue ;
		words = ft_split(lines[i], WHITESPACE);
		if (!words[0])
			continue ;
		key_index = find_key_index(words[0]);
		if (key_index == KEY_NUM || !parser[key_index](words))
		{
			ft_free_split(words, ft_arrsize(words));
			return (printf_error());
		}
		ft_free_split(words, ft_arrsize(words));
	}
	return (OK);
}

static int	fileread(char *file_name, char *file_data)
{
	char	ch;
	int		len;
	int		fd;
	int		s;

	fd = open(file_name, O_RDONLY);
	len = ft_strlen(file_name);
	if (fd < 0
		|| len < 3
		|| file_name[len - 3] != '.'
		|| file_name[len - 2] != 'r'
		|| file_name[len - 1] != 't')
		return (ERROR);
	s = read(fd, &ch, 1);
	while (s > 0)
	{
		*file_data++ = ch;
		s = read(fd, &ch, 1);
	}
	return (s >= 0);
}

int	input(int argc, char **argv)
{
	char	file_data[MAX_FILE_READ];

	if (argc == 2 && fileread(argv[1], file_data) && parsing(file_data))
		return (OK);
	return (ERROR);
}
