# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: su <su@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 00:01:37 by ycha              #+#    #+#              #
#    Updated: 2021/10/11 04:02:52 by su               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TEST_NAME	=	$(notdir $(shell pwd))

NAME		:=	$(TEST_NAME)

TEST_FILE	:=	$(TEST_NAME).c

all			:
	@$(MAKE) -C ../ TEST_NAME=$(TEST_NAME) test

test		:
	@gcc $(TEST_FILE) -o $(MLX_NAME) $(MLX_INCLUDE) $(MLX_CLIB)
	@install_name_tool -change libmlx.dylib $(MLX_PATH)/libmlx.dylib $(MLX_NAME)
	@gcc $(TEST_FILE) -o $(SDL_NAME) $(SDL_INCLUDE) $(SDL_CLIB)

fclean		:
	@rm -f $(NAME)

re			: fclean all

.PHONY: fclean all re test

