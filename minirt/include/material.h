/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:41 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 02:51:42 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H
# include <stdio.h>
# include "minirt.h"

# define MATERIAL_LAMBERTIAN			0
# define MATERIAL_METAL					1
# define MATERIAL_DIELECTRIC			2

typedef struct s_hit_record	t_hit_record;

// vector 구조체
typedef struct s_material
{
	int			type;
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
