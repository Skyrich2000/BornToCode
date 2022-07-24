/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:37:53 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:37:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	create_image_texture(t_texture *texture, char *name)
{
	texture->type = TEXTURE_IMAGE;
	texture->image = mlx_png_file_to_image(m()->scr.mlx, name, \
									&texture->width, &texture->height);
	printf("texture->loaded: %s\n", name);
	if (!texture->image)
		exit(1);
	texture->addr = mlx_get_data_addr(texture->image, &texture->bits_per_pixel, \
					&texture->line_length, &texture->endian);
	texture->value = &image_value;
}

t_texture	create_texture(t_clr color, char *name)
{
	t_texture	texture;

	texture.file_name = ft_strdup(name);
	texture.color = vec_divn(color, 255);
	if (name)
	{
		if (ft_strncmp(name, "checkerboard") == 0)
		{
			texture.type = TEXTURE_CHECKERBOARD;
			texture.value = &checkerboard_value;
		}
		else
			create_image_texture(&texture, name);
	}
	else
	{
		texture.type = TEXTURE_SOLID;
		texture.value = &solid_value;
	}
	return (texture);
}
