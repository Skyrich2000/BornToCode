# Color =================================================s

GREEN="\033[32m"
YELLOW="\033[33m"
RED="\033[31m"
BLUE="\033[34m"
RESET="\033[0m"

# File =================================================

NAME		=	phonebook

INCLUDE		=	./include
FILE		=	main.cpp \
				contact.cpp \
				utils.cpp \
				phonebook.cpp

SRC_DIR		=	./src
SRCS		= 	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.cpp,%.o,$(FILE)))

# var ==================================================

CC          =	g++
CFLAGS      =	-Wall -Werror -Wextra -std=c++98 -I $(INCLUDE)

# Rule =================================================

.PHONY	: all
all		: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo $(YELLOW)"Compiling... $<"$(RESET)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo $(GREEN)"Done!"$(RESET)

.PHONY	: clean
clean	:
	@echo $(RED)"Remove $(OBJ_DIR)..."$(RESET)
	@rm -rf $(OBJ_DIR)

.PHONY	: fclean
fclean	: clean
	@echo $(RED)"Remove $(NAME)..."$(RESET)
	@rm -f $(NAME)

.PHONY	: re
re		: fclean all