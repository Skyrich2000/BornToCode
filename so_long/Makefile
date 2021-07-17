# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 07:48:16 by ycha              #+#    #+#              #
#    Updated: 2021/07/17 04:28:05 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRCS	= ./srcs/main.c ./srcs/debug.c\
			./srcs/engine/game.c \
			./srcs/engine/sprite.c \
			./srcs/engine/draw.c \
			./srcs/engine/keyboard.c \
			./srcs/engine/instance.c \
			./srcs/engine/list.c \
			./srcs/engine/scene.c \
			./srcs/asset/asset.c \
			./srcs/asset/background/background_black.c \
			./srcs/asset/object/obj_player.c \
			./srcs/asset/object/obj_zombie.c \
			./srcs/asset/object/obj_avatar.c \
			./srcs/asset/scene/scene_play.c \
			./srcs/asset/sprite/spr_player.c \
			./srcs/asset/sprite/spr_zombie.c \
			./srcs/library/sl_free.c \
			./srcs/library/sl_itoa.c \
			./srcs/library/sl_strjoin.c

CC		=	gcc
INCLUDE =	-Iinclude -Isrcs/mlx
CLIB	=	-Lsrcs/mlx -lmlx -framework OpenGL -framework Appkit
CFLAGS	=	-Wall -Werror -Wextra $(INCLUDE)

OBJS	=	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) -o $@ $^
	./so_long

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)

re		: fclean all
