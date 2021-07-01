# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/07/02 00:01:39 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
BONUS_NAME	= checker

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
bonus: $(BONUS_NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) checker

re: fclean all

.PHONY: clean fclean all re
