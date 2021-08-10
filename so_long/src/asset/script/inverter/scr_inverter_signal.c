/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_inverter_signal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:51:46 by su                #+#    #+#             */
/*   Updated: 2021/08/10 18:55:58 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

#define	H		0
#define	V		1
#define	IN		2
#define	OUT		3

static void	set_mv(int mv_signal, int *h_mv, int *v_mv)
{
	*h_mv = \
		(((mv_signal & SIG_MV_RIGHT) > 0) - ((mv_signal & SIG_MV_LEFT) > 0));
	*v_mv = \
		(((mv_signal & SIG_MV_DOWN) > 0) - ((mv_signal & SIG_MV_UP) > 0));
}

void	scr_inverter_before(t_instance *this)
{
	int			mv[4];
	int			dir;
	int			dis;
	t_instance	*ins;

	mv[IN] = this->signal & 0b11110;
	mv[OUT] = this->obj.inverter.out_dir[mv[IN]];
	scr_inverter_destroy_trigger(this, mv[IN]);
	dir = (mv[IN] & (0b00110)) | (mv[OUT] & (0b00110));
	g()->global.player->signal = \
							SIG_MV_AUTO | mv[IN] | scr_convert_mv_signal(dir);
	set_mv(mv[IN], &mv[H], &mv[V]);
	dis = (this->x - g()->global.player->x) * mv[H] + \
					(this->y - g()->global.player->y) * mv[V];
	set_mv(mv[OUT], &mv[H], &mv[V]);
	ins = create_dummy_instance(this->x + mv[H] * (dis - 10), \
					this->y + mv[V] * dis, !this->obj.inverter.inverted, -1);
	ins->signal = SIG_MV_AUTO | \
				scr_reverse_mv_signal(mv[OUT]) | scr_convert_mv_signal(dir);
	this->obj.inverter.dummy = ins;
}

void	scr_inverter_active(t_instance *this)
{
	int	h_mv;
	int	v_mv;
	int	in_mv;
	int	out_mv;
	int	dir;

	g()->global.inverted = !this->obj.inverter.inverted;
	g()->global.invert_signal = SIG_ACTIVE;
	g()->global.player->signal = 0;
	g()->frame.skip_frame = 0;
	scr_avatarize(PLAYER);
	in_mv = this->signal & 0b11110;
	out_mv = this->obj.inverter.out_dir[in_mv];
	dir = this->signal & (SIG_DIR_LEFT | SIG_DIR_RIGHT);
	destroy_instance(this->obj.inverter.dummy);
	this->obj.inverter.dummy = 0;
	g()->global.player = create_player_instance(this->x, this->y);
	g()->global.player->signal = SIG_MV_AUTO | out_mv | dir;
	set_mv(out_mv, &h_mv, &v_mv);
	create_trigger_instance((int [2]){this->x + h_mv * 90, \
									this->y + v_mv * 90}, \
									!this->obj.inverter.inverted, \
									g()->global.player, 0);
}
