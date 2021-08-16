/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:05:56 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_DRAW_H
# define ENGINE_DRAW_H
# include "engine/engine_list.h"
# include "engine/engine_image.h"
# include "engine/engine_instance.h"
# include "engine/engine_font.h"

// draw function
void			draw_img(void *img, int x, int y);
void			draw_sprite(t_sprite *spr, t_list *img_node, int x, int y);
void			draw_self(t_instance *this);
void			draw_background(t_background *background);
void			draw_text(t_font *font, char *str, int pos[2], float align[2]);

// draw function for debug
void			draw_point(int x, int y, int color);
void			draw_bold_point(int x, int y, int color);
void			draw_line(int pos[2], int dir[2], int len, int color);
void			draw_box(t_box	box, int color);
void			draw_debug(void);

#endif