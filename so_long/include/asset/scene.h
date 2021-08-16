/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:05:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/11 10:05:46 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include "engine/engine.h"

# define NICK_SIZE			10

# define S_READY			-1
# define S_STRAIGHT			0
# define S_INVERT			1
# define S_RESTRAIGHT		2
# define S_CLEAR			3
# define S_GAMEOVER			4

// init scene
int			init_scene_main(void);
int			init_scene_nick(void);
int			init_scene_play(void);
int			init_scene_rank(void);

// scene main
void		scene_main_start(void);
void		scene_main_controller(void);
void		scene_main_ui(void);
void		scene_main_end(void);

// scene nickname
void		scene_nick_start(void);
void		scene_nick_controller(void);
void		scene_nick_ui(void);
void		scene_nick_end(void);

// scene play
void		scene_play_start(void);
void		scene_play_controller(void);
void		scene_play_ui(void);
void		scene_play_end(void);

// scene rank
void		scene_rank_start(void);
void		scene_rank_controller(void);
void		scene_rank_ui(void);
void		scene_rank_end(void);

#endif