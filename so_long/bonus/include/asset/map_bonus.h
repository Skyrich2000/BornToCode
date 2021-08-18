/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:05:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:06:43 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H
# include "engine/engine_bonus.h"

# define MAP_SIZE			11

// init map
int			init_map(void);

// maps
void		map_0_0(int *width, int *height);
void		map_0_1(int *width, int *height);
void		map_0_2(int *width, int *height);
void		map_0_3(int *width, int *height);
void		map_0_4(int *width, int *height);
void		map_0_5(int *width, int *height);
void		map_1(int *width, int *height);
void		map_2(int *width, int *height);
void		map_3(int *width, int *height);
void		map_4(int *width, int *height);
void		map_5(int *width, int *height);
void		map_6(int *width, int *height);

#endif
