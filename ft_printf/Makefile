CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -I . -c

NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				./srcs/boxing.c \
				./srcs/utils.c \
				./srcs/print.c \
				./srcs/parse.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

all			: $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) $< -o $@

libft/libft.a		:
	make all -C libft/

$(NAME)		: $(OBJS) libft/libft.a
	cp libft/libft.a $(NAME)
	ar -cr $(NAME) $?

bonus		: $(OBJS_BONUS) libft/libft.a
	cp libft/libft.a $(NAME)
	ar -cr $(NAME) $?

clean		:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	make clean -C libft

fclean		: clean
	rm -rf $(NAME)
	make fclean -C libft

re			: fclean all

.PHONY		: all bonus clean fclean re libft/libft.a
