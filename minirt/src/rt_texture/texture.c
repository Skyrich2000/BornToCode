/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:15:14 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:15:17 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_texture	create_texture(t_clr color, char *name)
{
	t_texture	texture;

	texture.color = vec_divn(color, 255);
	if (name)
	{
		if (ft_strncmp(name, "checkerboard") == 0)
			texture.value = &checkerboard_value;
		else
		{
			texture.image = mlx_png_file_to_image(m()->scr.mlx, name, \
											&texture.width, &texture.height);
			if (!texture.image)
				exit(1);
			texture.addr = mlx_get_data_addr(texture.image, \
										&texture.bits_per_pixel, \
										&texture.line_length, &texture.endian);
			texture.value = &image_value;
		}
	}
	else
		texture.value = &solid_value;
	return (texture);
}
