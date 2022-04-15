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

#define KEY_NUM 24

static void	parser_init(int (*parser[KEY_NUM])(char **))
{
	parser[0] = parse_r;
	parser[1] = parse_a;
	parser[2] = parse_c;
	parser[3] = parse_l;
	parser[4] = parse_sp;
	parser[5] = parse_pl;
	parser[6] = parse_sq;
	parser[7] = parse_cy;
	parser[8] = parse_tr;
	parser[9] = parse_sp_metal;
	parser[10] = parse_pl_metal;
	parser[11] = parse_sq_metal;
	parser[12] = parse_cy_metal;
	parser[13] = parse_tr_metal;
	parser[14] = parse_sp_dielectric;
	parser[15] = parse_pl_dielectric;
	parser[16] = parse_sq_dielectric;
	parser[17] = parse_cy_dielectric;
	parser[18] = parse_tr_dielectric;
	parser[19] = parse_sp_lambertian;
	parser[20] = parse_pl_lambertian;
	parser[21] = parse_sq_lambertian;
	parser[22] = parse_cy_lambertian;
	parser[23] = parse_tr_lambertian;
}

static int	find_key_index(char *key)
{
	int	j;

	j = -1;
	while (++j < KEY_NUM)
	{
		if (ft_strncmp(key, (char [KEY_NUM][15]){
			"R", "A", "c", "l", "sp", "pl", "sq", "cy", "tr", \
			"sp-metal", "pl-metal", "sq-metal", "cy-metal", "tr-metal", \
			"sp-dielectric", "pl-dielectric", "sq-dielectric", "cy-dielectric", \
			"tr-dielectric", "sp-lambertian", "pl-lambertian", "sq-lambertian", \
			"cy-lambertian", "tr-lambertian", \
			}[j]) == 0)
			break ;
	}
	return (j);
}

static int	parsing(char *file_data)
{
	int		i;
	int		key_index;
	int		(*parser[KEY_NUM])(char **);
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
	{
		close(fd);
		return (ERROR);
	}
	s = read(fd, &ch, 1);
	while (s > 0)
	{
		*file_data++ = ch;
		s = read(fd, &ch, 1);
	}
	close(fd);
	return (s >= 0);
}

int	input(int argc, char **argv)
{
	char	file_data[MAX_FILE_READ];

	if (argc == 2 && fileread(argv[1], file_data) && parsing(file_data))
		return (OK);
	return (ERROR);
}
