# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/07/05 16:01:45 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	../libftprintf.a

CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -Iinclude

FILE		=	ft_printf_bonus.c \
				core/boxing_bonus.c \
				core/get_arg_bonus.c \
				core/print_bonus.c \
				core/parse_bonus.c \
				utils/utils_bonus.c

SRC_DIR		=	./src
SCRS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

all			: $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(OBJS)
	ar -cr $@ $?

show			:
	@printf "NAME : $(NAME)\n"
	@printf "OBJS : $(OBJS)\n"

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette $(SRC_DIR)/*

clean		:
	rm -rf $(OBJ_DIR)

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all clean fclean re show norm
