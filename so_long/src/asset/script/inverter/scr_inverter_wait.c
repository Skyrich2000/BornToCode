/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_inverter_wait.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:48:54 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:50:55 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	scr_inverter_create_wait(t_instance *this)
{
	int	h_mv;
	int	v_mv;
	int	mv;
	int	reverse_mv;

	mv = SIG_MV_RIGHT;
	while (mv <= SIG_MV_DOWN)
	{
		if (this->obj.inverter.out_dir[mv])
		{
			reverse_mv = scr_reverse_mv_signal(mv);
			h_mv = (((reverse_mv & SIG_MV_RIGHT) > 0) - \
									((reverse_mv & SIG_MV_LEFT) > 0));
			v_mv = (((reverse_mv & SIG_MV_DOWN) > 0) - \
									((reverse_mv & SIG_MV_UP) > 0));
			this->obj.inverter.waits[mv] = \
				create_wait_instance(this->x + h_mv * 32, this->y + v_mv * 32);
		}
		mv = mv << 1;
	}
}

void	scr_inverter_destroy_wait(t_instance *this)
{
	int	mv;

	mv = SIG_MV_RIGHT;
	while (mv <= SIG_MV_DOWN)
	{
		if (this->obj.inverter.out_dir[mv])
			destroy_instance(this->obj.inverter.waits[mv]);
		mv = mv << 1;
	}
}
