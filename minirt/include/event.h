/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:45:34 by ycha              #+#    #+#             */
/*   Updated: 2021/05/17 03:44:17 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H
# include "minirt.h"

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_C			8
# define KEY_R			15
# define KEY_L			37
# define KEY_G			5
# define KEY_M			46
# define KEY_PLUS		24
# define KEY_MINUS		27
# define KEY_LEFT_SHIFT	257
# define KEY_SPACEBAR	49
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126

typedef struct s_screen	t_screen;

int		exit_hook(void);

void	key_camera_move(void);

int		key_up(int keycode);
int		key_down(int keycode);

int		mouse_up(void);
int		mouse_down(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);

#endif
