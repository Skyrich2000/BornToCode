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

SERVER_NAME	= server
CLIENT_NAME = client
SERVER_BONUS_NAME = server_bonus
CLIENT_BONUS_NAME = client_bonus

CFLAGS	= -Wall -Wextra -Werror -I.

SERVER_SRCS	= server.c lib.c
CLIENT_SRCS = client.c lib.c
SERVER_BONUS_SRCS = bonus/server_bonus.c bonus/lib_bonus.c
CLIENT_BONUS_SRCS = bonus/client_bonus.c bonus/lib_bonus.c

SERVER_OBJS	= $(SERVER_SRCS:%.c=%.o)
CLIENT_OBJS	= $(CLIENT_SRCS:%.c=%.o)
SERVER_BONUS_OBJS	= $(SERVER_BONUS_SRCS:%.c=%.o)
CLIENT_BONUS_OBJS	= $(CLIENT_BONUS_SRCS:%.c=%.o)

all: $(SERVER_NAME) $(CLIENT_NAME)

bonus: $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	gcc $(CFLAGS) -o $@ $^

$(CLIENT_NAME): $(CLIENT_OBJS)
	gcc $(CFLAGS) -o $@ $^

$(SERVER_BONUS_NAME): $(SERVER_BONUS_OBJS)
	gcc $(CFLAGS) -o $@ $^

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_OBJS)
	gcc $(CFLAGS) -o $@ $^

clean:
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)
	rm -f $(SERVER_BONUS_OBJS)
	rm -f $(CLIENT_BONUS_OBJS)


fclean: clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)
	rm -f $(SERVER_BONUS_NAME) $(CLIENT_BONUS_NAME)

re: fclean all

.PHONY: clean fclean all re
