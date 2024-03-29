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

SERVER_NAME	=	server
CLIENT_NAME =	client

CFLAGS		=	-Wall -Wextra -Werror -Iinclude

SERVER_FILE	=	core/server.c \
				lib/lib.c

CLIENT_FILE	=	core/client.c \
				lib/lib.c

SRC_DIR		=	./src
SERVER_SCRS	=	$(addprefix $(SRC_DIR)/, $(SERVER_FILE))
CLIENT_SRCS	=	$(addprefix $(SRC_DIR)/, $(CLIENT_FILE))

OBJ_DIR		=	./obj
SERVER_OBJS	=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(SERVER_FILE)))
CLIENT_OBJS	=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(CLIENT_FILE)))

export SERVER_FILE
export CLIENT_FILE

all				: $(SERVER_NAME) $(CLIENT_NAME)

bonus			:
	$(MAKE) -C bonus

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_NAME)	: $(SERVER_OBJS)
	gcc $(CFLAGS) -o $@ $^

$(CLIENT_NAME)	: $(CLIENT_OBJS)
	gcc $(CFLAGS) -o $@ $^

show			:
	$(MAKE) -C bonus show
	@printf "SERVER_NAME : $(SERVER_NAME)\n"
	@printf "SERVER_OBJS : $(SERVER_OBJS)\n"
	@printf "CLIENT_NAME : $(CLIENT_NAME)\n"
	@printf "CLIENT_OBJS : $(CLIENT_OBJS)\n"

norm			:
	$(MAKE) -C bonus norm
	@python3 -m norminette include/*
	@python3 -m norminette $(SRC_DIR)/*

clean			:
	$(MAKE) -C bonus clean
	rm -rf $(OBJ_DIR)

fclean			: clean
	$(MAKE) -C bonus fclean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re				: fclean all

.PHONY			: clean fclean all re norm show bonus
