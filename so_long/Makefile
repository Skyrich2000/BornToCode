# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 07:48:16 by ycha              #+#    #+#              #
#    Updated: 2021/07/20 03:10:47 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

SRC		= main.c debug.c\
			engine/game.c \
			engine/sprite.c \
			engine/draw.c \
			engine/keyboard.c \
			engine/instance.c \
			engine/list.c \
			engine/scene.c \
			asset/asset.c \
			asset/background/background_black.c \
			asset/object/obj_player.c \
			asset/object/obj_zombie.c \
			asset/object/obj_avatar.c \
			asset/scene/scene_play.c \
			asset/sprite/spr_player.c \
			asset/sprite/spr_zombie.c \
			library/sl_free.c \
			library/sl_itoa.c \
			library/sl_strjoin.c

SRC_DIR =	./src/
SRCS	= 	$(addprefix $(SRC_DIR), $(SRC))
CC		=	gcc
INCLUDE =	-Iinclude -Isrc/mlx
CLIB	=	-Lsrc/mlx -lmlx -framework OpenGL -framework Appkit
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
