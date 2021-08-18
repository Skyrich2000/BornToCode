# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 01:51:33 by ycha              #+#    #+#              #
#    Updated: 2021/08/19 01:51:34 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	../so_long_bonus

FILE		:=	$(patsubst %.c,%_bonus.c,$(FILE))

SRC_DIR		:=	./src
SRCS		:=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		:=	./obj
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

# Options =================================================

CC			=	gcc
INCLUDE 	=	-Iinclude -Isrc/mlx
CLIB		=	-Lsrc/mlx -lmlx -framework OpenGL -framework Appkit -g
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE)

SHELL		=	/bin/bash
sp			=	/-\|/
idx			=	0

# =========================================================

all				: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		echo -n "Loading ... ";\
	fi
	@printf "\b$(chr)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			: $(OBJS)
	@printf "\b "
	@$(MAKE) -C ./src/mlx > /dev/null 2>&1
	@$(CC) $(CFLAGS) $(CLIB) -o $@ $^
	@install_name_tool -change libmlx.dylib bonus/src/mlx/libmlx.dylib $(NAME)
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\e[1;33mso\e[1;31m long\e[1;37m \e[0;32mis Ready 💚\e[0m\n\n\n"
	@printf "████████╗███████╗███╗░░██╗╔███████╗░░░╔██░░░\n"
	@printf "╚══██╔══╝██╔════╝████╗░██║╚════╗██║░░░║██░░░\n"
	@printf "░░░██║░░░█████╗░░██╔██╗██║░░╔█████║░░░║██░░░\n"
	@printf "░░░██║░░░██╔══╝░░██║╚████║░░╚══╗██║░░░║██░░░\n"
	@printf "░░░██║░░░███████╗██║░╚███║╔███████║╔████████\n"
	@printf "░░░╚═╝░░░╚══════╝╚═╝░░╚══╝╚═══════╝╚═══════╝\n"
	@printf "\n\n"
	@cd ..; afplay ./res/bgm.mp3 -v 0.5 & ./so_long_bonus ./res/ber/map.ber ; pkill afplay

show			:
	@printf "NAME : $(NAME)\n"
	@printf "FILE : $(FILE)\n"
	@printf "OBJS : $(OBJS)\n"

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/main_bonus.c
	@python3 -m norminette src/asset/asset_bonus.c
	@python3 -m norminette src/asset/background/*
	@python3 -m norminette src/asset/font/*
	@python3 -m norminette src/asset/map/*
	@python3 -m norminette src/asset/object/*
	@python3 -m norminette src/asset/scene/*
	@python3 -m norminette src/asset/script/*
	@python3 -m norminette src/asset/sprite/*
	@python3 -m norminette src/engine/*
	@python3 -m norminette src/lib/*

clean			:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C ./src/mlx clean

fclean			: clean
	@rm -f $(NAME)

re				: fclean all

.PHONY			:	all clean fclean re show norm run
