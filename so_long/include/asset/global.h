/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:05:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:06:39 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include "engine/engine.h"
# include "asset/scene.h"

typedef struct s_global
{
	int				nick_index;
	char			nick[NICK_SIZE + 1];

	char			**rank_list;
	int				rank_list_y;

	int				steps;
	int				time;
	int				time_all_lv;
	int				delay;
	int				deathcount;
	int				max_time;
	int				state;
	int				text;
	int				inverted;
	int				invert_signal;
	int				gold_num;
	t_instance		*player;
	int				darkness;

	int				view_xview_aim;
	int				view_yview_aim;

	int				tutorial;
	int				map_index;
	int				map_width;
	int				map_height;
}	t_global;

#endif
