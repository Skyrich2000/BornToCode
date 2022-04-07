/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:16:13 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:16:14 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_clr	solid_value(t_texture *this, double u, double v)
{
	(void)u;
	(void)v;
	return (this->color);
}
