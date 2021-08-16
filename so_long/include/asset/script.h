/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:05:36 by ycha              #+#    #+#             */
/*   Updated: 2021/08/17 06:06:52 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCRIPT_H
# define SCRIPT_H
# include "engine/engine.h"

// scripts for scene nick
void		scr_nick_keycheck(char *ascii, char prev[50], char prev_backspace);
void		scr_nick_keysave(char prev[50], char *prev_backspace);
void		scr_nick_blink(void);

// scripts to save or load footprint
void		scr_save_footprint(t_instance *this, t_list *route);
void		scr_load_footprint(t_instance *this, t_list **route, int inverted);

// script to animation
void		scr_animation(t_instance *this);

// scripts to get route or route node
t_list		*scr_get_route(t_instance *id, int type);
t_list		**scr_get_route_node(t_instance *id, int type);

// script for trigger
void		scr_trigger(t_instance *trigger);

// script to move dummy
void		scr_dummy_move_auto(t_instance *this);

// scripts in player step
void		scr_player_step_signal(t_instance *this);
void		scr_player_step_normal(t_instance *this);
void		scr_player_step_avatar(t_instance *this);
// script for player to attack
void		scr_player_attack(t_instance *this);
// script to check if player is nearby
void		scr_player_check_selfs(t_instance *this);
// scripts for check player collision
int			scr_player_collision_box(t_instance *this);
void		scr_player_collision_gold(t_instance *this);
void		scr_player_collision_inverter(t_instance *this);
void		scr_player_collision_trigger(t_instance *this);
void		scr_player_collision_zombie(t_instance *this);
void		scr_player_collision_exit(t_instance *this);
void		scr_player_collision_wait(t_instance *this);
// script to get player sprite pointer
t_sprite	*scr_player_get_spr(int type, int inverted, int dir);
// scripts to move player
void		scr_player_move_auto(t_instance *this);
void		scr_player_move(t_instance *this);
// script kill all players when player dead
void		scr_player_die(int text, t_instance *focus);

// scirpt to mvoe zombie
void		scr_zombie_move(t_instance *this);

// script to manange instacne state
void		scr_avatarize(int type);
t_instance	*scr_find_dead_zombie(void);
t_instance	*scr_find_alive_gold(void);

// scripts for manage global state of game
void		scr_state_ready(void);
void		scr_state_straight(void);
void		scr_state_inverted(void);
void		scr_state_restraight(void);
void		scr_state_clear(void);
void		scr_state_gameover(void);

// scripts to draw play scene ui
void		scr_ui_light(void);
void		scr_ui_nick(int x1, int up_pad, int down_pad);
void		scr_ui_state(int x1, int len, int up_pad);
void		scr_ui_death(int x4, int up_pad, int down_pad);
void		scr_ui_step(int x3, int up_pad, int down_pad);
void		scr_ui_map(int x2, int up_pad, int down_pad);
void		scr_ui_time(void);
void		scr_ui_text(void);

// script to calculate signal
int			scr_reverse_mv_signal(int signal);
int			scr_convert_mv_signal(int signal);

// scripts to manage triggers from inverter
void		scr_inverter_create_trigger(t_instance *this);
void		scr_inverter_destroy_trigger(t_instance *this, int exclusive_sig);
// scripts to manage wait objects and invisible wall objects
void		scr_inverter_create_wait(t_instance *this);
void		scr_inverter_destroy_wait(t_instance *this);
// script when inverter received signal
void		scr_inverter_before(t_instance *this);
void		scr_inverter_active(t_instance *this);
// scripts in inverter step
void		scr_inverter_skip_frame(t_instance *this);
void		scr_inverter_change_sprite(t_instance *this);
void		scr_inverter_start(t_instance *this);

// script for build map from char** return width and height of map
void		scr_build_map(char **map, int *width, int *height);

// script for save rank
void		scr_save_rank(char *name, int time, int deathcount);

#endif
