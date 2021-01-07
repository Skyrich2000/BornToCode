CFLAGS = -Wall -Wextra -Werror
ARFLAGS = -rcs
NAME = libft.a
SRCDIR = srcs
INCDIR = includes
SRCS = $(wildcard $(SRCDIR)/*/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)
%.o: %.c
	gcc $(CFLAGS) -c $< -o  $@ -I $(INCDIR)
$(NAME): $(OBJS)
	ar $(ARFLAGS) -o $@ $^
so: $(OBJS)
	gcc -shared -o libft.so $^
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
	rm -f libft.so
re: fclean all
