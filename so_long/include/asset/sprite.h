/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:05:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:06:54 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H
# include "engine/engine.h"

// init sprite
int			init_spr_player_blue(void);
int			init_spr_player_red(void);
int			init_spr_zombie(void);
int			init_spr_empty(void);
int			init_spr_wall(void);
int			init_spr_light(void);
int			init_spr_box(void);
int			init_spr_gold(void);
int			init_spr_inverter(void);
int			init_spr_exit(void);
int			init_spr_plane(void);
int			init_spr_logo(void);
int			init_spr_state(void);

#endif
