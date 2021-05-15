#include "minirt.h"

int		in_shadow(t_world *world, t_ray *light_ray, double light_len)
{
	t_hit_record rec;

	if (hit_world(world, light_ray, (double[2]){EPSILON, light_len}, &rec))
		return (OK);
	return (ERROR);
}

t_light		*init_light()
{
	t_light	*head;

	head = (t_light *)malloc(sizeof(t_light));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int		add_light(t_light *head, t_pnt origin, t_clr color, double ratio)
{
	t_light *light;

	light = malloc(sizeof(t_light));
	if (!light)
		return (ERROR);
	light->origin = origin;
	light->color = color;
	light->ratio = ratio;
	light->next = head->next;
	head->next = light;
	return (OK);
}

t_clr light_get(t_world *world, t_hit_record *rec, t_light *light)
{
	t_clr	diffuse;
	t_vec	light_dir;
	double	kd; // diffuse의 강도
	// specular lighting
	t_clr specular;
	t_vec view_dir;
	t_vec refl_dir;
	double spec;
	double ksn;
	double ks;
	//
	// shadow
	double light_len;
	t_ray light_ray;
	//
	double brightness;

	// shadow
	light_ray.dir = vec_cal((t_vec[2]){light->origin, rec->p}, (double[2]){1, -1}, 2);
	light_ray.origin = vec_cal((t_vec[2]){rec->p, rec->n}, (double[2]){1, EPSILON}, 2);
	light_len = vec_length(&light_ray.dir);
	if (in_shadow(world, &light_ray, light_len))
		return (vec(0,0,0));
	light_dir = vec_unit(light_ray.dir);
	kd = ft_max(vec_dot(rec->n, light_dir), 0.0);// (교점에서 출발하여 광원을 향하는 벡터)와 (교점에서의 법선벡터)의 내적값.
	diffuse = vec_muln(light->color, kd);
	// specular lighting
	view_dir = vec_unit(vec_oppo(rec->rayin));
	refl_dir = reflect(vec_oppo(light_dir),rec->n);
	ksn = 28;
	ks = 0.25;
	spec = pow(ft_max(vec_dot(view_dir, refl_dir), 0.0), ksn);
	specular = vec_muln(vec_muln(light->color, ks), spec);
	//
	return (vec_add(diffuse, specular));
	// brightness = light->ratio * LUMEN;
	// return (vec_muln(vec_add(vec_add(diffuse, world->ambient) ,specular), brightness));
}

t_clr phong(t_world *world, t_hit_record *rec)
{
	t_clr		color;
	t_light		*light;

	light = world->light->next;
	color = (t_clr){0, 0, 0};
	while(light)
	{
		color = vec_add(color, light_get(world, rec, light));
		light = light->next;
	}
	color = vec_add(color, world->ambient);
	return (vec_min(vec_mul(color, rec->albedo), vec(1, 1, 1)));
}