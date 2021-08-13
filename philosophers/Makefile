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

NAME	= philo

CFLAGS	= -Wall -Wextra -Werror -Iinclude

SRCS	= src/main.c \
			src/lib/lib.c \
			src/core/philo.c \
			src/core/data.c \
			src/core/input.c \
			src/core/utils.c

OBJS	= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $^ -lpthread

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re

