/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkboard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:15:32 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:15:33 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_clr	checkboard_value(t_texture *this, double u, double v)
{
	const int		width = 4;
	const int		height = 4;
	const double	u2 = floor(u * width);
	const double	v2 = floor(v * height);

	if (fmod(u2 + v2, 2.) == 0)
		return (this->color);
	return (vec(1, 1, 1));
}
