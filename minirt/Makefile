# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycha <ycha@gmail.com>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 15:07:00 by suhshin           #+#    #+#              #
#    Updated: 2022/02/24 22:43:08 by ycha             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color =================================================s

GREEN="\033[32m"
YELLOW="\033[33m"
RED="\033[31m"
BLUE="\033[34m"
RESET="\033[0m"

# File =================================================

NAME			=	minirt

INCLUDE         =   ./include
FILE			=	\
					minirt.c \
					rt_vector/vector1.c \
					rt_vector/vector2.c \
					rt_vector/vector3.c \
					rt_vector/vector4.c \
					rt_vector/vector5.c \
					rt_vector/vector6.c \
					rt_vector/vector7.c \
					rt_event/key.c	\
					rt_event/mouse_down.c \
					rt_event/mouse_move_up.c \
					rt_camera/camera.c \
					rt_camera/render.c \
					rt_camera/render_pixel.c \
					rt_camera/draw_gui.c \
					rt_camera/set_gui.c \
					rt_camera/set_get_object.c \
					rt_object/world.c \
					rt_object/sphere.c \
					rt_object/plane.c \
					rt_object/square.c \
					rt_object/cylinder.c \
					rt_object/triangle.c \
					rt_library/lib1.c \
					rt_library/lib2.c \
					rt_library/lib3.c \
					rt_library/lib4.c \
					rt_library/lib5.c \
					rt_library/lib6.c \
					rt_material/lambertian.c \
					rt_material/metal.c \
					rt_material/dielectric.c \
					rt_texture/texture.c \
					rt_texture/checkboard.c \
					rt_texture/image.c \
					rt_texture/solid.c \
					rt_parsing/parse.c \
					rt_parsing/parse1.c \
					rt_parsing/parse2.c \
					rt_parsing/util.c \
					rt_light/light.c \
					rt_light/phong.c

SRC_DIR         =	./src
SRCS            =	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR         =	./obj
OBJS            =	$(addprefix $(OBJ_DIR)/, $(patsubst %.c,%.o,$(FILE)))


# var ==================================================

CC		=	gcc
CFLAGS	=	-I$(INCLUDE) -I./src/mlx #-Wall -Werror -Wextra 
CLIB	=	-Lsrc/mlx -lmlx -framework OpenGL -framework Appkit -lpthread -L/opt/homebrew/opt/zlib/lib -lz

# Rule =================================================

.PHONY  : all
all		: $(NAME)

$(OBJ_DIR)/%.o  : $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo $(YELLOW)"Compiling... $<"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -s -C ./src/mlx
	@$(CC) $(CFLAGS) $(CLIB) -o $@ $^
	@echo $(GREEN)"Done!"$(RESET)

.PHONY  : run
run		:
	@echo $(YELLOW)"Running... ./$(NAME)"$(RESET)
	@./$(NAME) maps/1.rt

.PHONY  : norm
norm	:
	python3 -m norminette $(SRCS)
	python3 -m norminette $(INCLUDE)

.PHONY  : clean
clean	:
	@$(MAKE) -C ./src/mlx clean
	@echo $(RED)"Remove $(OBJ_DIR)..."$(RESET)
	@rm -rf $(OBJ_DIR)

.PHONY  : fclean
fclean	: clean
	@echo $(RED)"Remove $(NAME)..."$(RESET)
	@rm -rf	$(NAME)

.PHONY  : re
re		: fclean all
