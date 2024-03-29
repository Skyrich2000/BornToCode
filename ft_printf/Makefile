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

NAME		=	libftprintf.a

CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -Iinclude

FILE		=	ft_printf.c \
				core/boxing.c \
				core/get_arg.c \
				core/print.c \
				core/parse.c \
				utils/utils.c

SRC_DIR		=	./src
SCRS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

all			: $(NAME)

bonus		:
	$(MAKE) -C bonus

%.o			: %.c
	$(CC) $(CFLAGS) $< -o $@

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)		: $(OBJS)
	ar -cr $@ $?

test			:
	cd ./test && ./grademe.sh

show			:
	$(MAKE) -C bonus show
	@printf "NAME : $(NAME)\n"
	@printf "OBJS : $(OBJS)\n"

norm			:
	$(MAKE) -C bonus norm
	@python3 -m norminette include/*
	@python3 -m norminette $(SRC_DIR)/*

clean		:
	$(MAKE) -C bonus clean
	rm -rf $(OBJ_DIR)

fclean		: clean
	$(MAKE) -C bonus fclean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all bonus clean fclean re show norm test
