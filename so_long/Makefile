# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 07:48:16 by ycha              #+#    #+#              #
#    Updated: 2021/07/24 16:13:44 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

FILE	= main debug \
			engine/game \
			engine/sprite \
			engine/draw \
			engine/keyboard \
			engine/instance \
			engine/list \
			engine/scene \
			engine/font \
			asset/asset \
			asset/background/background_map1 \
			asset/font/font_default \
			asset/object/obj_player \
			asset/object/obj_zombie \
			asset/object/obj_wall \
			asset/object/obj_box \
			asset/object/obj_gold \
			asset/object/obj_inverter \
			asset/object/obj_trigger \
			asset/object/obj_dummy \
			asset/scene/scene_play \
			asset/script/dummy/scr_dummy_move \
			asset/script/inverter/scr_inverter \
			asset/script/player/scr_player_attack \
			asset/script/player/scr_player_check_selfs \
			asset/script/player/scr_player_collision \
			asset/script/player/scr_player_get_spr \
			asset/script/player/scr_player_move \
			asset/script/player/scr_player_die \
			asset/script/play/scr_avatarize \
			asset/script/play/scr_state \
			asset/script/trigger/scr_trigger \
			asset/script/zombie/scr_zombie_move \
			asset/script/scr_footprint \
			asset/script/scr_animation \
			asset/script/scr_get_route \
			asset/sprite/spr_player_red \
			asset/sprite/spr_player_blue \
			asset/sprite/spr_zombie \
			asset/sprite/spr_empty \
			asset/sprite/spr_wall \
			asset/sprite/spr_box \
			asset/sprite/spr_exit \
			asset/sprite/spr_gold \
			asset/sprite/spr_inverter \
			lib/sl_free \
			lib/sl_itoa \
			lib/sl_strjoin

SRC_DIR =	./src/
SRCS	= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILE)))
OBJS	=	$(addprefix $(SRC_DIR), $(addsuffix .o, $(FILE)))

CC		=	gcc
INCLUDE =	-Iinclude -Isrc/mlx
CLIB	=	-Lsrc/mlx -lmlx -framework OpenGL -framework Appkit
CFLAGS	=	-Wall -Werror -Wextra $(INCLUDE)

SHELL	=	/bin/bash
sp		=	/-\|/
idx		=	0

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
	@$(CC) $(CFLAGS) $(CLIB) -o $@ $^
	@install_name_tool -change libmlx.dylib src/mlx/libmlx.dylib $(NAME)
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\e[1;33mso\e[1;31m long\e[1;37m \e[0;32mis Ready 💚\e[0m\n\n\n"
	@printf "██╗░░░██╗███████╗███╗░░██╗███████╗██╗░░░██╗\n"
	@printf "██║░░░██║██╔════╝████╗░██║██╔════╝██║░░░██║\n"
	@printf "╚██╗░██╔╝█████╗░░██╔██╗██║█████╗░░╚██╗░██╔╝\n"
	@printf "░╚████╔╝░██╔══╝░░██║╚████║██╔══╝░░░╚████╔╝░\n"
	@printf "░░╚██╔╝░░███████╗██║░╚███║███████╗░░╚██╔╝░░\n"
	@printf "░░░╚═╝░░░╚══════╝╚═╝░░╚══╝╚══════╝░░░╚═╝░░░\n"
	@printf "\n\n"
	@./so_long

clean	:
	@rm -f $(OBJS)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all

.PHONY	:	all clean fclean re bonus



# i=1
# j=0
# max=20000

# printf "\033[0;31m"
# echo -n "Loading... "
# echo -n ' '
# while [ $j -lt $max ]
# do
#     printf "\b${sp:i++%${#sp}:1}"
#     j=$(($j+1))
# done
