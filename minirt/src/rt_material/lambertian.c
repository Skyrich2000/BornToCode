/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:32:19 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:32:19 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	create_lambertian(t_texture texture)
{
	t_material	mat;

	mat.type = MATERIAL_LAMBERTIAN;
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
