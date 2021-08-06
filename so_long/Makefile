# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 07:48:16 by ycha              #+#    #+#              #
#    Updated: 2021/08/04 21:06:37 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

ENGINE		=	game.c \
				image.c \
				draw.c \
				draw_debug.c \
				keyboard.c \
				instance.c \
				list.c \
				scene.c \
				input.c \
				font.c

BACKGROUND	=	background_main.c \
				background_nick.c \
				background_map.c \
				background_rank.c

FONT		=	font_su.c \
				font_fat.c

MAP			=	map.c \
				map_0.c \
				map_1.c \
				map_2.c \
				map_3.c \
				map_4.c \
				map_5.c \
				map_1_2.c \
				map_1_3.c

OBJECT		=	obj_player.c \
				obj_zombie.c \
				obj_wall.c \
				obj_wall_up.c \
				obj_box.c \
				obj_gold.c \
				obj_inverter.c \
				obj_trigger.c \
				obj_dummy.c \
				obj_exit.c \
				obj_plane.c

SCENE		=	scene_main.c \
				scene_nick.c \
				scene_play.c \
				scene_rank.c

SCRIPT		=	dummy/scr_dummy_move.c \
				inverter/scr_inverter_signal.c \
				inverter/scr_inverter_trigger.c \
				player/scr_player_attack.c \
				player/scr_player_check_selfs.c \
				player/scr_player_collision.c \
				player/scr_player_get_spr.c \
				player/scr_player_move.c \
				player/scr_player_die.c \
				trigger/scr_trigger.c \
				zombie/scr_zombie_move.c \
				play/scr_avatarize.c \
				play/scr_state.c \
				scr_footprint.c \
				scr_animation.c \
				scr_get_route.c \
				scr_build_map.c \
				scr_signal.c \
				scr_save_rank.c

SPRITE		=	spr_player_red.c \
				spr_player_blue.c \
				spr_zombie.c \
				spr_empty.c \
				spr_light.c \
				spr_wall.c \
				spr_box.c \
				spr_exit.c \
				spr_plane.c \
				spr_logo.c \
				spr_state.c \
				spr_gold.c \
				spr_inverter.c

LIB			=	sl_free.c \
				sl_itoa.c \
				sl_strjoin.c \
				sl_split.c \
				sl_rev_atoi.c \
				sl_strchr.c \
				sl_atoi.c \
				sl_exit.c

SRCS		=	src/main.c \
				src/asset/asset.c \
				$(addprefix src/engine/, $(ENGINE)) \
				$(addprefix src/asset/background/, $(BACKGROUND)) \
				$(addprefix src/asset/font/, $(FONT)) \
				$(addprefix src/asset/map/, $(MAP)) \
				$(addprefix src/asset/object/, $(OBJECT)) \
				$(addprefix src/asset/scene/, $(SCENE)) \
				$(addprefix src/asset/script/, $(SCRIPT)) \
				$(addprefix src/asset/sprite/, $(SPRITE)) \
				$(addprefix src/lib/, $(LIB))

OBJS		=	$(patsubst %.c,%.o,$(SRCS))

CC			=	gcc
INCLUDE 	=	-Iinclude -Isrc/mlx
CLIB		=	-Lsrc/mlx -lmlx -framework OpenGL -framework Appkit
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE)

SHELL		=	/bin/bash
sp			=	/-\|/
idx			=	0

all		: $(NAME)

norm	:
	norminette $(SCRS)

%.o		: %.c
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		echo -n "Loading ... ";\
	fi
	@printf "\b$(chr)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: $(OBJS)
	@printf "\b "
	@$(MAKE) -C ./src/mlx > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(CLIB) -o $@ $^
	@install_name_tool -change libmlx.dylib src/mlx/libmlx.dylib $(NAME)
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\e[1;33mso\e[1;31m long\e[1;37m \e[0;32mis Ready 💚\e[0m\n\n\n"
	@printf "████████╗███████╗███╗░░██╗╔███████╗░░░╔██░░░\n"
	@printf "╚══██╔══╝██╔════╝████╗░██║╚════╗██║░░░║██░░░\n"
	@printf "░░░██║░░░█████╗░░██╔██╗██║░░╔█████║░░░║██░░░\n"
	@printf "░░░██║░░░██╔══╝░░██║╚████║░░╚══╗██║░░░║██░░░\n"
	@printf "░░░██║░░░███████╗██║░╚███║╔███████║╔████████\n"
	@printf "░░░╚═╝░░░╚══════╝╚═╝░░╚══╝╚═══════╝╚═══════╝\n"
	@printf "\n\n"
	@afplay bgm.mp3 & ./so_long map.ber ; pkill afplay

run		:
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\e[1;33mso\e[1;31m long\e[1;37m \e[0;32mis Ready 💚\e[0m\n\n\n"
	@printf "████████╗███████╗███╗░░██╗╔███████╗░░░╔██░░░\n"
	@printf "╚══██╔══╝██╔════╝████╗░██║╚════╗██║░░░║██░░░\n"
	@printf "░░░██║░░░█████╗░░██╔██╗██║░░╔█████║░░░║██░░░\n"
	@printf "░░░██║░░░██╔══╝░░██║╚████║░░╚══╗██║░░░║██░░░\n"
	@printf "░░░██║░░░███████╗██║░╚███║╔███████║╔████████\n"
	@printf "░░░╚═╝░░░╚══════╝╚═╝░░╚══╝╚═══════╝╚═══════╝\n"
	@printf "\n\n"
	@afplay bgm.mp3 & ./so_long map.ber ; pkill afplay

clean	:
	@rm -f $(OBJS)
	@make -C ./src/mlx clean

fclean	: clean
	@rm -f $(NAME)

re		: fclean all

.PHONY	:	all clean fclean re bonus
