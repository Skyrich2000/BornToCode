# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/07/04 03:06:23 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME	= server
CLIENT_NAME = client

CFLAGS	= -Wall -Wextra -Werror -I.

SERVER_SRCS	= server.c lib.c
CLIENT_SRCS = client.c lib.c

SERVER_OBJS	= $(SERVER_SRCS:%.c=%.o)
CLIENT_OBJS	= $(CLIENT_SRCS:%.c=%.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	gcc $(CFLAGS) -o $@ $^

$(CLIENT_NAME): $(CLIENT_OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)

fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: clean fclean all re
