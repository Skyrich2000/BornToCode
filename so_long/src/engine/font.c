/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:08 by ycha              #+#    #+#             */
/*   Updated: 2021/08/03 03:03:40 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

t_font	*add_font(char *path, int size)
{
	t_font	*new;
	char	*str[3];
	int		temp[2];
	void	*img;
	int		i;

	new = (t_font *)malloc(sizeof(t_font));
	if (!new)
		sl_exit(12);
	i = -1;
	while (++i < 127)
	{
		str[0] = sl_itoa(i);
		str[1] = sl_strjoin(path, str[0]);
		str[2] = sl_strjoin(str[1], ".png");
		img = mlx_png_file_to_image(g()->mlx, str[2], &temp[0], &temp[1]);
		if (img)
			new->real_size = temp[0];
		new->img[i] = img;
		sl_free_arr3(str);
	}
	new->size = size;
	return (new);
}
