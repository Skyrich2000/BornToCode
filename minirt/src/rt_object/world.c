/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:34:22 by ycha              #+#    #+#             */
/*   Updated: 2022/04/15 03:34:22 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_world	*init_world(void)
{
	t_world	*head;

	head = (t_world *)malloc(sizeof(t_world));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int	add_world(
	int type,
	int is_material_fixed,
	t_object obj,
	t_material material
) {
	int		(*hits[5])(struct s_world *this, \
							t_ray *ray, double minmax[2], t_hit_record *out);
	t_world	*new;

	hits[PLANE] = hit_plane;
	hits[SPHERE] = hit_sphere;
	hits[CYLINDER] = hit_cylinder;
	hits[SQUARE] = hit_square;
	hits[TRIANGLE] = hit_triangle;
	new = (t_world *)malloc(sizeof(t_world) * 1);
	if (!new)
		return (ERROR);
	new->type = type;
	new->is_material_fixed = is_material_fixed;
	new->obj = obj;
	new->hit = hits[type];
	new->material = material;
	new->next = m()->wrd->next;
	m()->wrd->next = new;
	return (OK);
}

// type 을 넣을까요?
// min값은 ray의
// ray가 특정 object에 맞았다면 max value를 바꿔준다.
// 이때 위의 함수가 true가 되려면 맞았을때의 t값이 min < t < max 이여야한다.
int	hit_world(t_ray *ray, double minmax[2], t_hit_record *out)
{
	t_hit_record	temp_rec;
	t_world			*w;
	int				flag;

	flag = 0;
	w = m()->wrd;
	while (w->next)
	{
		w = w->next;
		if (w->hit(w, ray, minmax, &temp_rec))
		{
			minmax[1] = temp_rec.t;
			*out = temp_rec;
			flag = 1;
		}
	}
	return (flag);
}

// 만약 위에서 구한 법선벡터와 ray의 방향벡터(어차피 둘다 단위벡터로 만들었음)의
// 내적값이 양수이면 예각이므로 n의 방향을 반대로 해주어야 한다
void	set_rec(t_world *this, t_ray *ray, t_hit_record *rec)
{
	rec->rayin = ray->dir;
	rec->front_face = vec_dot_(&ray->dir, &rec->n) < 0;
	if (!rec->front_face)
		rec->n = vec_oppo(rec->n);
	rec->material = &this->material;
	rec->is_material_fixed = this->is_material_fixed;
}

t_clr	get_rec_color(t_hit_record *rec)
{
	t_texture	*texture;

	if (!m()->texture_toggle)
		return (rec->material->texture.color);
	texture = &rec->material->texture;
	return (texture->value(texture, rec->u, rec->v));
}
