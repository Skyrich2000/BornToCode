# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 07:48:16 by ycha              #+#    #+#              #
#    Updated: 2021/08/01 15:25:29 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

ENGINE		=	game \
				image \
				draw \
				keyboard \
				instance \
				list \
				scene \
				input \
				font

BACKGROUND	=	background_main \
				background_nick \
				background_map \
				background_rank

FONT		=	font_su \
				font_fat

MAP			=	map \
				map_0 \
				map_1 \
				map_2 \
				map_3

OBJECT		=	obj_player \
				obj_zombie \
				obj_wall \
				obj_wall_up \
				obj_box \
				obj_gold \
				obj_inverter \
				obj_trigger \
				obj_dummy \
				obj_exit \
				obj_plane

SCENE		=	scene_main \
				scene_nick \
				scene_play \
				scene_rank

SCRIPT		=	dummy/scr_dummy_move \
				inverter/scr_inverter_signal \
				inverter/scr_inverter_trigger \
				player/scr_player_attack \
				player/scr_player_check_selfs \
				player/scr_player_collision \
				player/scr_player_get_spr \
				player/scr_player_move \
				player/scr_player_die \
				trigger/scr_trigger \
				zombie/scr_zombie_move \
				play/scr_avatarize \
				play/scr_state \
				scr_footprint \
				scr_animation \
				scr_get_route \
				scr_build_map \
				scr_signal \
				scr_save_rank

SPRITE		=	spr_player_red \
				spr_player_blue \
				spr_zombie \
				spr_empty \
				spr_light \
				spr_wall \
				spr_box \
				spr_exit \
				spr_plane \
				spr_logo \
				spr_gold \
				spr_inverter

LIB			=	sl_free \
				sl_itoa \
				sl_strjoin \
				sl_split \
				sl_rev_atoi \
				sl_strchr

FILE		=	main \
				asset/asset \
				$(addprefix engine/, $(ENGINE)) \
				$(addprefix asset/background/, $(BACKGROUND)) \
				$(addprefix asset/font/, $(FONT)) \
				$(addprefix asset/map/, $(MAP)) \
				$(addprefix asset/object/, $(OBJECT)) \
				$(addprefix asset/scene/, $(SCENE)) \
				$(addprefix asset/script/, $(SCRIPT)) \
				$(addprefix asset/sprite/, $(SPRITE)) \
				$(addprefix lib/, $(LIB))

SRC_DIR 	=	./src/
SRCS		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILE)))
OBJS		=	$(addprefix $(SRC_DIR), $(addsuffix .o, $(FILE)))

CC			=	gcc
INCLUDE 	=	-Iinclude -Isrc/mlx
CLIB		=	-Lsrc/mlx -lmlx -framework OpenGL -framework Appkit
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE)

SHELL		=	/bin/bash
sp			=	/-\|/
idx			=	0

all		: $(NAME)

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
	@$(MAKE) -C ./src/mlx
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
	@./so_long map.ber

clean	:
	@rm -f $(OBJS)
	@make -C ./src/mlx clean

fclean	: clean
	@rm -f $(NAME)

re		: fclean all

.PHONY	:	all clean fclean re bonus
