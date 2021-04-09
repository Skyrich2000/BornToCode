#include "object.h"
#include "stdlib.h"

t_world		*set_world()
{
	t_world	*head;

	head = (t_world *)malloc(sizeof(t_world));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int	world_add(t_world *head, t_object obj, int (*hit)(t_object *obj, t_ray *ray, double minmax[2], t_hit_record *out))
{
	t_world *new;

	new = (t_world *)malloc(sizeof(t_world) * 1);
	if(!new)
		return (0);
	new->obj = obj;
	new->next = head->next;
	new->hit = hit;
	head->next = new;
	return (1);
}

int			world_hit(t_world *head, t_ray *ray, double minmax[2], t_hit_record *out)
{
	t_hit_record temp_rec;
	double	closest;
	int		flag;
	t_world *w;

	closest = minmax[1]; // max
	flag = 0;
	w = head;

	while (w->next)
	{
		w = w->next;
		if (w->hit(&w->obj, ray, minmax, &temp_rec)) {
			flag = 1;
			closest = temp_rec.t;
			*out = temp_rec;
		}
	}

	return (flag);
}
