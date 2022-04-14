/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:23 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:51:24 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include <stdio.h>
# include "minirt.h"

# define TEXTURE_SOLID			0
# define TEXTURE_CHECKERBOARD	1
# define TEXTURE_IMAGE			2

typedef struct s_texture
{
	int				type;
	t_clr			color;
	void			*image;
	void			*addr;
	int				height;
	int				width;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	struct s_vec	(*value)(struct s_texture *this, double u, double v);
}	t_texture;

t_texture	create_texture(t_clr color, char *name);

t_clr		solid_value(struct s_texture *this, double u, double v);
t_clr		checkerboard_value(struct s_texture *this, double u, double v);
t_clr		image_value(struct s_texture *this, double u, double v);

#endif
