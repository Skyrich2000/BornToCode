# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/16 07:48:16 by ycha              #+#    #+#              #
#    Updated: 2021/07/22 03:50:26 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES : .c .o
NAME	= so_long

FILE	= main debug\
			engine/game \
			engine/sprite \
			engine/draw \
			engine/keyboard \
			engine/instance \
			engine/list \
			engine/scene \
			engine/font \
			asset/asset \
			asset/background/background_black \
			asset/font/font_default \
			asset/object/obj_player \
			asset/object/obj_zombie \
			asset/object/obj_wall \
			asset/object/obj_box \
			asset/script/scr_footprint \
			asset/script/scr_animation \
			asset/script/scr_get_route \
			asset/scene/scene_play \
			asset/sprite/spr_player \
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

all		: $(NAME)

.o		: .c
	@$(CC) $(CFLAGS) $(CLIB) -c $< -o  $@

$(NAME)	: $(OBJS)
	@$(CC) $(CFLAGS) $(CLIB) -o $@ $^
	@./so_long

clean	:
	@rm -f $(OBJS)

fclean	: clean
	@rm -f $(NAME)

re		: fclean all
