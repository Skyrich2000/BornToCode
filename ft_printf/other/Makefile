# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 21:38:42 by jiwchoi           #+#    #+#              #
#    Updated: 2021/02/09 14:36:14 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= ./libft

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= ft_join.c \
		  ft_parse.c \
		  ft_printf.c \
		  ft_to.c \
		  ft_type.c

BSRCS	=

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $@ $^

bonus : $(BOBJS)
	$(AR) $(NAME) $^

all : $(NAME)

clean :
	make -C $(LIBFT) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
