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
			./srcs/asset/asset.c \
			./srcs/asset/player.c \
			./srcs/asset/zombie.c \
			./srcs/asset/round.c \
			./srcs/asset/avatar.c \
			./srcs/library/library.c

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
