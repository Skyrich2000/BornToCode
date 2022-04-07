/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:53:05 by ycha              #+#    #+#             */
/*   Updated: 2022/04/07 20:53:06 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
# include <stdio.h>
# include "minirt.h"

typedef struct s_hit_record	t_hit_record;

// vector 구조체
typedef struct s_material
{
	t_texture	texture;
	double		fuzz;
	double		ir;
	int			(*scatter)(struct s_material *this, t_ray *ray_in, \
									t_hit_record *rec, t_ray *ray_out);
}	t_material;

t_material	create_lambertian(t_texture texture);
t_material	create_metal(t_texture texture, double fuzz);
t_material	create_dielectric(double ir);

int			scatter_lambertian(struct s_material *this, t_ray *ray_in, \
									t_hit_record *rec, t_ray *ray_out);
int			scatter_metal(struct s_material *this, t_ray *ray_in, \
									t_hit_record *rec, t_ray *ray_out);
int			scatter_dielectric(t_material *this, t_ray *ray_in, \
									t_hit_record *rec, t_ray *ray_out);

#endif
