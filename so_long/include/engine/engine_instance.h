/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@gmail.com>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 07:48:32 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:05:56 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_INSTANCE_H
# define ENGINE_INSTANCE_H
# include "engine/engine_list.h"
# include "engine/engine_image.h"
# include "asset/object.h"

typedef struct s_box
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}	t_box;

typedef struct s_instance
{
	t_list			*node;
	t_object		obj;
	t_sprite		*spr;
	t_list			*img_node;
	int				draw_time;
	int				x;
	int				y;
	int				dir;
	int				condition;
	int				signal;
	void			(*step)(struct s_instance	*);
	void			(*draw)(struct s_instance	*);
}	t_instance;

// instance function
t_instance		*create_instance(t_sprite *spr, int data[3], \
				void (*step)(t_instance *this), void (*draw)(t_instance *this));
int				place_meeting(t_instance *id, int x, int y, t_instance *other);
t_instance		*place_meeting_type(t_instance *id, int x, int y, int type);
void			destroy_instance(t_instance *id);
void			destroy_all_instance(void);

#endif