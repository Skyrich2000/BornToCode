/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:36:59 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:37:00 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_clr	checkerboard_value(t_texture *this, double u, double v)
{
	const int		width = 10;
	const int		height = 10;
	const double	u2 = floor(u * width);
	const double	v2 = floor(v * height);

	if (fmod(u2 + v2, 2.) == 0)
		return (this->color);
	return (vec(1, 1, 1));
}
