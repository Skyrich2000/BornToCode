# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/07/03 16:17:25 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
BONUS_NAME	=	checker

CFLAGS		=	-Wall -Wextra -Werror -Iinclude

FILE		=	push_swap.c \
				core/input.c \
				core/func.c \
				core/list/list1.c core/list/list2.c \
				core/sort/sort_quick.c core/sort/sort_small.c \
				lib/lib.c lib/lib_split.c lib/lib_gnl.c

BONUS_FILE	=	checker.c \
				core/input.c \
				core/func.c \
				core/list/list1.c core/list/list2.c \
				lib/lib.c lib/lib_split.c lib/lib_gnl.c

SRC_DIR		=	./src
SRCS		= 	$(addprefix $(SRC_DIR)/, $(FILE))
BONUS_SRCS	= 	$(addprefix $(SRC_DIR)/, $(BONUS_FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))
BONUS_OBJS	=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(BONUS_FILE)))

all: $(NAME) $(BONUS_NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJS)
	gcc $(CFLAGS) -o $@ $^

test			:
	cd ./test/push_swap_tester && \
	./push_swap_tester.bash

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/*

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: clean fclean all re norm test
