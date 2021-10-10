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

MLX_PATH			=	../../minilibx-swift
SDL_PATH			=	../../

TESTS				=	\
            			test_fps_blank \
						test_init \
						test_key_hook \
						test_loop \
						test_loop_hook \
						test_multi_window \
						test_png_image \
						test_window \
						test_window_destroy

# =========================================================

export MLX_INCLUDE 	=	-I$(MLX_PATH)
export MLX_CLIB		=	-L$(MLX_PATH) -lmlx -framework OpenGL -framework Appkit

export SDL_INCLUDE 	=	-I$(SDL_PATH)
export SDL_CLIB		=	-L$(SDL_PATH) -lmlx -lSDL2 -lSDL2_image

export MLX_PATH

# =========================================================

all				:
	@$(MAKE) -C ../
	@for DIRS in $(TESTS); do \
		printf "[TEST] $$DIRS"; \
		$(MAKE) -C $$DIRS test; \
		printf " ... done!\n"; \
	done

test			:
	@$(MAKE) -C ../
	@printf "[TEST] $(TEST_NAME)";
	@$(MAKE) -C $(TEST_NAME) test;
	@printf " ... done!\n"; \

show			:
	@printf "MLX_PATH : $(MLX_PATH)\n"
	@printf "SDL_PATH : $(SDL_PATH)\n"
	@printf "TESTS : $(TESTS)\n"

fclean			:
	@$(MAKE) -C ../ fclean
	@for DIRS in $(TESTS); do \
		$(MAKE) -C $$DIRS fclean; \
	done

re				: fclean all

.PHONY: fclean all re show

