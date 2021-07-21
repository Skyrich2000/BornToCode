#include "engine.h"

/*
** dir 이 0 이면 순행
** dir 이 1 이면 역행
*/
t_instance *create_avatar_instance(t_list *route, int dir)
{
	t_list		*node;
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_empty, (int[3]){AVATAR, 0, 0}, obj_avatar_step, obj_avatar_draw);
	if (!ins)
		return (ERROR);
	node = route->next;
	if (g()->global.inverted == dir)
		while(node && node->next)
			node = node->next;
	ins->obj.avatar.route = route;
	ins->obj.avatar.node = node;
	ins->dir = dir;
	return (ins);
}

/*
** 인버전 0
** 순행 0 -> 정상
** 역행 1 -> 거꾸로
** 인버전 1
** 순행 0 -> 거꾸로
** 역행 1 -> 정상
** 인버전 == 진행 -> 정상
*/
void		obj_avatar_step(t_instance *this)
{
	t_footprint *fp;
	t_list	*prev_node;

	prev_node = this->obj.avatar.node;
	if (g()->global.inverted == this->dir)
		this->obj.avatar.node = this->obj.avatar.node->prev;
	else
		this->obj.avatar.node = this->obj.avatar.node->next;
	if (!this->obj.avatar.node)
		this->obj.avatar.node = prev_node;
	fp = this->obj.avatar.node->data;
	this->x = fp->x;
	this->y = fp->y;
	this->spr = fp->spr;
	this->img_node = fp->img_node;
}

void		obj_avatar_draw(t_instance *this)
{
	draw_sprite(this->spr, this->img_node, this->x, this->y);
}
