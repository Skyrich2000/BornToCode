#include "engine.h"

void		scr_animation(t_instance *this)
{
	if (this->draw_time > this->spr->img_speed)
	{
		this->img_node = this->img_node->next;
		this->draw_time = 0;
	}
	if (!this->img_node)
		this->img_node = this->spr->imgs->next;
}
