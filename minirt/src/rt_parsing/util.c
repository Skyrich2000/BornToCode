/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:34:57 by echung            #+#    #+#             */
/*   Updated: 2022/03/06 23:35:00 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	printf_error(void)
{
	printf("parsing error\n");
	return (ERROR);
}

int	parse_split(t_vec *input, char *line)
{
	char	**tmp;

	tmp = ft_split(line, ",");
	if (ft_arrsize(tmp) != 3
		|| !ft_atod(&input->x, tmp[0])
		|| !ft_atod(&input->y, tmp[1])
		|| !ft_atod(&input->z, tmp[2]))
		return (ERROR);
	ft_free_split(tmp, ft_arrsize(tmp));
	return (OK);
}

int	free_lines_and_words(char **lines, char **words)
{
	ft_free_split(lines, ft_arrsize(lines));
	ft_free_split(words, ft_arrsize(words));
	return (printf_error());
}
