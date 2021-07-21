NAME	=	so_long

CC		=	gcc
INCLUDE = 	-Iinclude -Isrc/mlx
CFLAGS	=	-Wall -Wextra -Werror $(INCLUDE)
SRC		=	main.c debug.c \
			engine/game.c \
			engine/sprite.c \
			engine/draw.c \
			engine/keyboard.c \
			engine/instance.c \
			engine/list.c \
			engine/scene.c \
			engine/font.c \
			asset/asset.c \
			asset/background/background_black.c \
			asset/font/font_default.c \
			asset/object/obj_player.c \
			asset/object/obj_zombie.c \
			asset/object/obj_wall.c \
			asset/object/obj_box.c \
			asset/script/scr_footprint.c \
			asset/script/scr_animation.c \
			asset/script/scr_get_route.c \
			asset/scene/scene_play.c \
			asset/sprite/spr_player_red.c \
			asset/sprite/spr_player_blue.c \
			asset/sprite/spr_zombie.c \
			asset/sprite/spr_empty.c \
			asset/sprite/spr_wall.c \
			asset/sprite/spr_box.c \
			asset/sprite/spr_exit.c \
			asset/sprite/spr_gold.c \
			asset/sprite/spr_inverter.c \
			lib/sl_free.c \
			lib/sl_itoa.c \
			lib/sl_strjoin.c

SRC_DIR = ./src/
CLIB	=	-Lsrc/mlx -lmlx -framework OpenGL -framework Appkit
SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJ = $(SRCS:.c=.o)

all		:	$(NAME)

%.o		:	$(SRC_DIR)/%.c
			$(CC) $(CFLAGS) $(CLIB) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $(NAME)


bonus	: all

clean	:
			rm -f $(OBJ)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean	all

.PHONY	:	all clean fclean re bonus
