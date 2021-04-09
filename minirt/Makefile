# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:07:00 by suhshin           #+#    #+#              #
#    Updated: 2021/04/08 15:23:57 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out

SRCS	=	\
			minirt.c \
			./srcs/rt_vector/vector.c \
			./srcs/rt_event/event.c	\
			./srcs/rt_object/sphere.c \
			./srcs/rt_camera/camera.c \
			./srcs/rt_camera/render.c \
			./srcs/rt_object/world.c
#
#
#

SRC_DIR	=	./srcs

INCLUDE =	-Iinclude -Isrcs/mlx -I./

OBJS = $(SRCS:%.c=%.o)

#
# Compiler and flags
#

CC		=	clang
CFLAGS	=	#-Wall -Werror -Wextra
CLIB	=	-Lsrcs/mlx -lmlx -framework OpenGL -framework Appkit $(INCLUDE)

#
# Rules
#

all		: $(NAME)

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)
	install_name_tool -change libmlx.dylib srcs/mlx/libmlx.dylib $(NAME)

clean	:
	rm -rf $(OBJS)

fclean	: clean
	rm -rf	$(NAME)

re		: fclean all
