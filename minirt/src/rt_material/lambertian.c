/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:14:31 by echung            #+#    #+#             */
/*   Updated: 2022/04/07 20:14:33 by echung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	create_lambertian(t_texture texture)
{
	t_material	mat;

	mat.texture = texture;
	mat.scatter = scatter_lambertian;
	return (mat);
}

// or random_unit_vector + near_zero
// random value에 의한 정점좌표를 새로 지정
int	scatter_lambertian(
	t_material *this,
	t_ray *ray_in,
	t_hit_record *rec,
	t_ray *ray_out
) {
	t_vec	target;

	(void)this;
	(void)ray_in;
	target = random_in_hemisphere(&rec->n);
	ray_out->origin = rec->p;
	ray_out->dir = target;
	return (1);
}
