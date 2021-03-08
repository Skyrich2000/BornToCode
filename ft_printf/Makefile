CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -I includes -c

NAME		=	libftprintf.a
SRCS		=	srcs/ft_printf.c \
				srcs/build_arg.c \
				srcs/get_arg.c \
				srcs/parse.c \
				srcs/ft_string.c \
				srcs/ft_itoa_base.c \
				srcs/ft_itoa_base_unsigned.c \
				srcs/init.c \
OBJS		=	$(SRCS:.c=.o)

all			: $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME)		: $(OBJS)
	make all -C libft/
	cp libft/libft.a $(NAME)
	ar -cr $(NAME) $(OBJS)

clean		:
	rm -rf $(OBJS)
	make clean -C libft

fclean		: clean
	rm -rf $(NAME)
	make fclean -C libft

re			: fclean all

.PHONY		: all bonus clean fclean re
