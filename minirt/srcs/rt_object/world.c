#include "object.h"

t_world		*init_world()
{
	t_world	*head;

	head = (t_world *)malloc(sizeof(t_world));
	if (!head)
		return (0);
	head->next = 0;
	return (head);
}

int			add_world(t_world *head, t_object obj, int (*hit)(t_world *this, t_ray *ray, double minmax[2], t_hit_record *out), t_material *material)
{
        t_world *new;

	new = (t_world *)malloc(sizeof(t_world) * 1);
	if(!new)
		return (0);
	new->obj = obj;
	new->hit = hit;
	new->material = material;
	new->next = head->next;
	head->next = new;
	return (1);
}

int			hit_world(t_world *head, t_ray *ray, double minmax[2], t_hit_record *out)
{
	t_hit_record temp_rec;
	t_world *w;
	int		flag;

	flag = 0;		// ray 가 object에 맞았는지 맞지 않았는지 flag
	w = head;
	while (w->next)
	{
		w = w->next;
		if (w->hit(w, ray, minmax, &temp_rec)) { // min값은 ray의
			minmax[1] = temp_rec.t; // ray가 특정 object에 맞았다면 max value를 바꿔준다.
			*out = temp_rec;		// 이때 위의 함수가 true가 되려면 맞았을때의 t값이 min < t < max 이여야한다.
			flag = 1;
		}
	}
	return (flag);
}
