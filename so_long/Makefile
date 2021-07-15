
NAME	= so_long

SRCS	= ./srcs/main.c \
			./srcs/engine/game.c \
			./srcs/engine/sprite.c \
			./srcs/engine/draw.c \
			./srcs/engine/keyboard.c \
			./srcs/engine/instance.c \
			./srcs/engine/list.c \
			./srcs/asset/asset.c \
			./srcs/asset/player.c

CC		=	gcc
INCLUDE =	-Iinclude -Isrcs/mlx
CLIB	=	-Lsrcs/mlx -lmlx -framework OpenGL -framework Appkit
CFLAGS	=	-Wall -Werror -Wextra $(INCLUDE)

OBJS	=	$(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) -o $@ $^
	./so_long

clean	:
	rm -f $(OBJS)

fclean	: clean
	rm -f $(NAME)
