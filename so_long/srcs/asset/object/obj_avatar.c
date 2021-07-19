#include "engine.h"

// dir 이 1 이면 역행
// dir 이 0 이면 순행
t_instance *create_avatar_instance(t_list *route, int dir)
{
	t_list		*node;
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_player_idle_right, (int[3]){AVATAR, 0, 0}, obj_avatar_step, obj_avatar_draw);
	if (!ins)
		return (ERROR);
	node = route->next;
	if (!dir)
		while(node && node->next)
			node = node->next;
	ins->obj.avatar.node = node;
	ins->dir = dir;
	return (ins);
}

void		obj_avatar_step(t_instance *this)
{
	if (!this->obj.avatar.node)
	{
		if (g()->global.status == 0)
			g()->global.status = 1;
		if (g()->global.status == 2)
			g()->global.status = 3;
		destroy_instance(this);
		return ;
	}
	if (this->dir)
		this->obj.avatar.node = this->obj.avatar.node->next;
	else
		this->obj.avatar.node = this->obj.avatar.node->prev;
}

void		obj_avatar_draw(t_instance *this)
{
	t_footprint *fp;

	if (this->obj.avatar.node)
	{
		fp = this->obj.avatar.node->data;
		if (fp)
			draw_subimg(fp->img, fp->x, fp->y);
	}
}
