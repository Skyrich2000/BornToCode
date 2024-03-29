/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector7.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:19:38 by echung            #+#    #+#             */
/*   Updated: 2022/03/06 23:19:41 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	random_in_unit_sphere(void)
{
	t_vec	out;

	while (1)
	{
		out = vec(rand_num(1, -1, 1), rand_num(1, -1, 1), rand_num(1, -1, 1));
		if (vec_length_squared_(&out) >= 1)
			continue ;
		return (out);
	}
}

t_vec	random_unit_vector(void)
{
	t_vec	tmp;

	tmp = random_in_unit_sphere();
	return (vec_unit_(&tmp));
}

// In the same hemisphere as the normal
t_vec	random_in_hemisphere(t_vec *normal)
{
	t_vec	in_unit_sphere;

	in_unit_sphere = random_in_unit_sphere();
	if (vec_dot_(&in_unit_sphere, normal) > 0.0)
		return (in_unit_sphere);
	else
		return (vec_cal((t_vec [1]){in_unit_sphere}, (double [1]){-1}, 1));
}
