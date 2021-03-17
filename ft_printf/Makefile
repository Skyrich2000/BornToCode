CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -I . -c

NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				./srcs/boxing.c \
				./srcs/print.c \
				./srcs/parse.c

SRCS_BONUS	=	ft_printf_bonus.c \
				./srcs_bonus/boxing_bonus.c \
				./srcs_bonus/get_arg_bonus.c \
				./srcs_bonus/print_bonus.c \
				./srcs_bonus/parse_bonus.c

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
	make clean -C libft

fclean		: clean
	rm -rf $(NAME)
	make fclean -C libft

re			: fclean all

.PHONY		: all bonus clean fclean re libft/libft.a
