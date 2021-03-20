CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -I . -c

NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				./srcs/boxing.c \
				./srcs/get_arg.c \
				./srcs/utils.c \
				./srcs/print.c \
				./srcs/parse.c

OBJS		=	$(SRCS:.c=.o)

all			: $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME)		: $(OBJS)
	ar -cr $@ $?

clean		:
	rm -rf $(OBJS)

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all bonus clean fclean re
