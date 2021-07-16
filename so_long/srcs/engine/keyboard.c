/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:49:11 by ycha              #+#    #+#             */
/*   Updated: 2021/07/16 07:49:11 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int		keyboard_check(int keycode)
{
    return (g()->keys[keycode]);
}

int		key_press(int keycode)
{
    g()->keys[keycode] = 1;
	return (OK);
}

int		key_release(int keycode)
{
    g()->keys[keycode] = 0;
	return (OK);
}
