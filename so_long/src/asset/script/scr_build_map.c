/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_build_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:16:47 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:16:49 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine/engine.h"

void	scr_build_map(char **map, int *j, int *i)
{
	t_instance	*(*func[127])(int, int);

	sl_bzero(func, sizeof(func));
	func[(int) '1'] = create_wall_instance;
	func[(int) 'Z'] = create_zombie_blue_instance;
	func[(int) 'B'] = create_box_red_instance;
	func[(int) '4'] = create_box_blue_instance;
	func[(int) 'C'] = create_gold_red_instance;
	func[(int) 'E'] = create_exit_instance;
	func[(int) 'P'] = create_player_instance;
	*i = -1;
	while (map[++(*i)])
	{
		*j = -1;
		while (map[*i][++(*j)])
		{
			if (func[(int)map[*i][*j]])
				func[(int)map[*i][*j]](*j * 32, *i * 32);
		}
	}
}
