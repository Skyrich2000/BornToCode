/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:56:12 by ycha              #+#    #+#             */
/*   Updated: 2021/04/06 22:02:09 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cal(t_vec *out, t_vec *v, double *a, int n)
{
	out->x = 0;
	out->y = 0;
	out->z = 0;
	while (n--)
	{
		out->x += v[n].x * a[n];
		out->y += v[n].y * a[n];
		out->z += v[n].z * a[n];
	}
}

int		main(void)
{
	t_vec sum;
	t_vec v1;
	t_vec v2;
	t_vec v3;

	vec3_init(&v1, 1.0, 1.0, 1.0);
	vec3_init(&v2, 2.0, 2.0, 2.0);
	vec3_init(&v3, 3.0, 3.0, 3.0);
	cal(&sum, (t_vec[3]){v1, v2, v3}, (double[3]){1.0, 1.0, 1.0}, 3);
	vec_print(&sum);
	return (0);
}
