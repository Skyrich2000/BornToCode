/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:53:15 by ycha              #+#    #+#             */
/*   Updated: 2022/04/07 21:43:44 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include <stdio.h>
# include "minirt.h"

typedef struct s_texture
{
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
t_clr		checkboard_value(struct s_texture *this, double u, double v);
t_clr		image_value(struct s_texture *this, double u, double v);

#endif
