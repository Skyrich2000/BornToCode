# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/08/13 01:21:19 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

# FILE =================================================

FILE		=	\
				main.c \
				core/builtin/builtin_cd.c \
				core/builtin/builtin_pwd.c \
				core/builtin/builtin.c \
				core/env/env.c \
				core/env/path.c \

				core/excute/excute.c \ 
				
				core/parse/lexer.c \
				core/parse/parse.c \ 
				core/parse/tokenizer.c \
				
				utils/ft_exit.c \
				utils/ft_strjoins.c \ 

				utils/list.c \ 


# Options =================================================

CC			=	gcc
INCLUDE 	=	-Iinclude
CFLAGS		=	-Wall -Werror -Wextra $(INCLUDE) -g

SRC_DIR		=	./src
SRCS		=	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))

# =========================================================

all				: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			: $(OBJS)
	gcc $(CFLAGS) -o $@ $^

norm			:
	@python3 -m norminette include/*
	@python3 -m norminette src/*

show			:
	@printf "SRCS : $(SRCS)"
	@printf "OBJS : $(OBJS)"

clean			:
	rm -rf $(OBJ_DIR)

fclean			: clean
	rm -f $(NAME)

re				: fclean all

.PHONY: clean fclean all re norm show

