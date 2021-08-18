/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_font.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:07:11 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_FONT_BONUS_H
# define ENGINE_FONT_BONUS_H

typedef struct s_font
{
	void			*img[127];
	int				size;
	int				real_size;
}	t_font;

// manage font asset
t_font			*add_font(char *path, int size);

#endif
