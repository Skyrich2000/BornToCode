# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echung <echung@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 22:13:22 by echung            #+#    #+#              #
#    Updated: 2021/06/27 17:01:28 by echung           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BNOUS_NAME	= checker

CFLAGS	= -Wall -Wextra -Werror -I.

SRCS	= push_swap.c input.c \
			list1.c list2.c func.c \
			lib1.c lib2.c lib3.c \
			sort_quick.c sort_small.c

BONUS_SRCS	= checker.c input.c \
			list1.c list2.c func.c \
			lib1.c lib2.c lib3.c

OBJS	= $(SRCS:%.c=%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

all: $(NAME)
bonus: $(BNOUS_NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

$(BNOUS_NAME): $(BONUS_OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: clean fclean all re
