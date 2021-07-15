
NAME	= so_long

SRCS	= ./srcs/main.c \
			./srcs/engine/game.c \
			./srcs/engine/sprite.c \
			./srcs/engine/draw.c \
			./srcs/engine/list.c \
			./srcs/asset/player.c

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
INCLUDE =	-Iinclude -Isrcs/mlx
CLIB	=	-Lsrcs/mlx -lmlx -framework OpenGL -framework Appkit

OBJS = $(SRCS:%.c=%.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(INCLUDE) main.c -o $@ $^

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)
