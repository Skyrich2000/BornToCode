/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:11 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 19:28:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	keyboard_check(int keycode)
{
	return (g()->keys[keycode]);
}

int	key_press(int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(g()->mlx, g()->win);
		exit(0);
	}
	g()->keys[keycode] = 1;
	return (OK);
}

int	key_release(int keycode)
{
	g()->keys[keycode] = 0;
	return (OK);
}

int	exit_press(void)
{
	exit(0);
}
