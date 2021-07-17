#include "engine.h"

// dir 이 1 이면 역행
// dir 이 0 이면 순행
t_instance *create_avatar_instance(t_list *route, int dir)
{
	t_list		*node;
	t_instance	*ins;

	ins = create_instance(g()->asset.spr_player_idle_right, (int[3]){AVATAR, 0, 0}, obj_avatar_draw, obj_avatar_draw);
	if (!ins)
		return (ERROR);
	node = route->next;
	if (!dir)
		while(node && node->next)
			node = node->next; // not checked
	ins->obj.avatar.node = node;
	ins->dir = dir;
	return (ins);
}
/*
static int			footprint_cmp(t_footprint *fp, t_footprint *prev_fp)
{
	if (fp->x == prev_fp->x && \
		fp->y == prev_fp->y && \
		fp->dir == prev_fp->dir)
		return (1);
	return (0);
}
*/
void		obj_avatar_step(t_instance *this)
{
	//t_footprint *fp;
	//t_footprint *prev_fp;

	// 멈춰있을때, 왼쪽일때, 오른쪽일떄
	//prev_fp = this->obj.avatar.node->data;
	//fp = this->obj.avatar.node->next->data;
	if (this->dir)
		this->obj.avatar.node = this->obj.avatar.node->next;
	else
		this->obj.avatar.node = this->obj.avatar.node->prev;
	/*
	if (footprint_cmp(fp, prev_fp))
	{
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_player_idle_right);
		else
			change_sprite(this, g()->asset.spr_player_idle_left);
	}
	else
	{
		if (this->dir == 1)
			change_sprite(this, g()->asset.spr_player_move_right);
		else
			change_sprite(this, g()->asset.spr_player_move_right);
	}
	*/
}

void		obj_avatar_draw(t_instance *this)
{
	t_footprint *fp;

	fp = this->obj.avatar.node->next->data;
	draw_subimg(fp->img, fp->x, fp->y);
}
