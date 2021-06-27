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
CFLAGS	= #-Wall -Wextra -Werror -I.
SRCS	= main.c \
			list.c list_sub.c func.c \
			lib1.c lib2.c \
			quick_sort.c sort_small.c


OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
