/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_key.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:07:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_KEY_BONUS_H
# define ENGINE_KEY_BONUS_H

# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_W			13
# define KEY_R			15
# define KEY_SPACEBAR	49
# define KEY_LEFT		123
# define KEY_DOWN		125
# define KEY_RIGHT		124
# define KEY_UP			126
# define KEY_I			34
# define KEY_P			35
# define KEY_ENTER		36
# define KEY_BACKSPACE	51

// key hook function
int				exit_press(void);
int				key_press(int keycode);
int				key_release(int keycode);

// check if keyboard is press
int				keyboard_check(int keycode);

#endif
