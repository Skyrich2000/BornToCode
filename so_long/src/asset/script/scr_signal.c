/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scr_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: su <su@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:13:47 by su                #+#    #+#             */
/*   Updated: 2021/08/10 16:13:48 by su               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int	scr_reverse_mv_signal(int signal)
{
	return ((signal & 0b10100) >> 1 | (signal & 0b1010) << 1);
}

int	scr_convert_mv_signal(int signal)
{
	if (signal & (SIG_MV_RIGHT | SIG_MV_LEFT))
		return (signal << 4);
	return (signal << 2);
}
