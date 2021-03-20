CC			= 	gcc
CFLAGS		=	-Wextra -Wall -Werror -I . -c

NAME		=	libftprintf.a
SRCS		=	ft_printf.c \
				./srcs/boxing.c \
				./srcs/get_arg.c \
				./srcs/utils.c \
				./srcs/print.c \
				./srcs/parse.c

SRCS_BONUS	=	ft_printf_bonus.c \
				./srcs_bonus/boxing_bonus.c \
				./srcs_bonus/get_arg_bonus.c \
				./srcs_bonus/utils_bonus.c \
				./srcs_bonus/print_bonus.c \
				./srcs_bonus/parse_bonus.c

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

all			: $(NAME)

%.o			: %.c
	$(CC) $(CFLAGS) $< -o $@

$(NAME)		: $(OBJS)
	ar -cr $@ $?

bonus		: $(OBJS_BONUS)
	ar -cr $(NAME) $?

clean		:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean		: clean
	rm -rf $(NAME)

re			: fclean all

.PHONY		: all bonus clean fclean re
