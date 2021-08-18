/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:29 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:08:19 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_bonus.h"

int	sl_abs(int a)
{
	return (a * ((a > 0) * 2 - 1));
}
