CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -I . -c

NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				./srcs/print_other.c \
				./srcs/print_number.c \
				./srcs/get_arg.c \
				./srcs/parse.c
OBJS		=	$(SRCS:.c=.o)

all			: $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME)		: $(OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME)
	echo $(OBJS)
	ar -cr $(NAME) $(OBJS)

clean		:
	rm -rf $(OBJS)
	make clean -C libft

fclean		: clean
	rm -rf $(NAME)
	make fclean -C libft

re			: fclean all

.PHONY		: all bonus clean fclean re
