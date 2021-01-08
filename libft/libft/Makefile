CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = rcs

NAME = libft.a
INCDIR = includes

CFILE_P1 = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_toupper.c \
       ft_tolower.c\
       ft_memset.c \
       ft_bzero.c \
       ft_memcpy.c \
       ft_memccpy.c \
       ft_memmove.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_calloc.c \
       ft_strlen.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_strnstr.c \
       ft_strncmp.c \
       ft_atoi.c \
       ft_strdup.c

CFILE_P2 = ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

CFILE_B = ft_lstnew.c \
	 ft_lstadd_front.c \
	 ft_lstsize.c \
	 ft_lstlast.c \
	 ft_lstadd_back.c \
	 ft_lstdelone.c \
	 ft_lstclear.c \
	 ft_lstiter.c \
	 ft_lstmap.c

SRCS_P1 = $(addprefix srcs/part1/, $(CFILE_P1))
SRCS_P2 = $(addprefix srcs/part2/, $(CFILE_P2))
SRCS_B = $(addprefix srcs/bonus/, $(CFILE_B))
SRCS_P = $(SRCS_P1) \
	 $(SRCS_P2)

OBJS_P = $(SRCS_P:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o  $@ -I $(INCDIR)

$(NAME): $(OBJS_P)
	$(AR) $(ARFLAGS) -o $@ $^

bonus: $(OBJS_B)
	$(AR) $(ARFLAGS) -o $(NAME) $^

so: $(OBJS_P) $(OBJS_B)
	$(CC) -shared -o libft.so $^

clean:
	rm -f $(OBJS_P)
	rm -f $(OBJS_B)

fclean: clean
	rm -f $(NAME)
	rm -f libft.so

re: clean all

.PHONY: bouns all clean fclean re
