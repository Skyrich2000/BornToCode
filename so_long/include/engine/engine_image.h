/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_image.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:07:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_IMAGE_H
# define ENGINE_IMAGE_H
# include "engine/engine_list.h"
# include "engine/engine_instance.h"

# define C_RED			0xFF0000
# define C_YELLOW		0xFFFF00
# define C_GREEN		0x00FF00
# define C_BLUE			0x0000FF

# define A_LEFT			0.0f
# define A_UP			0.0f
# define A_CENTER		0.5f
# define A_RIGHT		1.0f
# define A_BOTTOM		1.0f

typedef struct s_sprite
{
	t_list			*imgs;
	int				width;
	int				height;
	int				img_speed;
	int				offset_x;
	int				offset_y;
	t_box			mask;
}	t_sprite;

typedef struct s_background
{
	void			*img;
	int				x;
	int				y;
	int				width;
	int				height;
}	t_background;

// manage image asset
t_sprite		*add_sprite(int offsetx, int offsety, int img_spd, t_box mask);
t_background	*add_background(char *path, int x, int y);
int				add_sprite_subimage(t_sprite *spr, char *path, int st, int end);

// sprite function
void			change_sprite(t_instance *id, t_sprite *spr);

#endif
