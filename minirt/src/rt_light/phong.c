/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:29:37 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:29:38 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	_hit_world(t_ray *ray, double minmax[2])
{
	t_hit_record	temp_rec;
	t_world			*w;
	int				flag;

	flag = 0;
	w = m()->wrd;
	while (w->next)
	{
		w = w->next;
		if (w->material.type == MATERIAL_DIELECTRIC)
			continue ;
		if (w->hit(w, ray, minmax, &temp_rec))
		{
			minmax[1] = temp_rec.t;
			flag = 1;
		}
	}
	return (flag);
}

static int	in_shadow(t_ray *light_ray, double light_len)
{
	light_ray->dir = vec_unit_(&light_ray->dir);
	if (!_hit_world(light_ray, (double [2]){EPSILON, light_len}))
		return (ERROR);
	return (OK);
}

static t_clr	get_specular(t_hit_record *rec, t_light *light, t_vec light_dir)
{
	t_vec			view_dir;
	t_vec			refl_dir;
	double			spec;

	view_dir = vec_unit(vec_oppo(rec->rayin));
	refl_dir = reflect(vec_oppo(light_dir), rec->n);
	spec = pow(ft_max(vec_dot(view_dir, refl_dir), 0.0), KSN);
	return (vec_muln(vec_muln(light->color, KS), spec));
}

// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
static t_clr	get_light_color(t_hit_record *rec, t_light *light)
{
	t_clr			diffuse;
	t_vec			light_dir;
	double			kd;
	t_clr			specular;
	t_ray			light_ray;

	light_ray.dir = vec_cal((t_vec [2]){light->origin, rec->p}, \
							(double [2]){1, -1}, 2);
	light_ray.origin = vec_cal((t_vec [2]){rec->p, rec->n}, \
							(double [2]){1, EPSILON}, 2);
	if (in_shadow(&light_ray, vec_length_(&light_ray.dir)))
		return (vec(0, 0, 0));
	light_dir = vec_unit(light_ray.dir);
	kd = ft_max(vec_dot(rec->n, light_dir), 0.0);
	diffuse = vec_muln(light->color, kd);
	specular = get_specular(rec, light, light_dir);
	return (vec_muln(vec_add(diffuse, specular), light->ratio * LUMEN));
}

t_clr	phong(t_hit_record *rec)
{
	t_clr		material_color;
	t_clr		color;
	t_light		*light;

	material_color = get_rec_color(rec);
	if (!m()->ray_mode \
		|| !m()->light_toggle \
		|| rec->material->type == MATERIAL_DIELECTRIC)
		return (material_color);
	light = m()->light->next;
	color = (t_clr){0, 0, 0};
	while (light)
	{
		color = vec_add(color, get_light_color(rec, light));
		light = light->next;
	}
	color = vec_add(color, vec_muln(m()->light->color, m()->light->ratio));
	return (vec_min(vec_mul(color, material_color), vec(1, 1, 1)));
}
