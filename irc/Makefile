# Color =================================================s

GREEN="\033[32m"
YELLOW="\033[33m"
RED="\033[31m"
BLUE="\033[34m"
RESET="\033[0m"

# File =================================================

NAME		=	ircserv

INCLUDE		=	-I./include -I./include/core/controller -I./include/core/model -I./include/core/service -I./include/network
FILE		=	main.cpp \
				core/controller/Controller.cpp \
				core/controller/UserMiddleware.cpp \
				core/model/User.cpp \
				core/model/Channel.cpp \
				core/model/Repository.cpp \
				core/service/Service.cpp \
				core/service/QuitService.cpp \
				core/service/NickService.cpp \
				core/service/PassService.cpp \
				core/service/UserService.cpp \
				core/service/JoinService.cpp \
				core/service/TopicService.cpp \
				core/service/NamesService.cpp \
				core/service/ListService.cpp \
				core/service/PartService.cpp \
				core/service/PrivmsgService.cpp \
				core/service/ModeService.cpp \
				network/Message.cpp \
				network/StatusCode.cpp \
				network/Network.cpp \
				network/Event.cpp \
				Util.cpp


SRC_DIR		=	./src
SRCS		= 	$(addprefix $(SRC_DIR)/, $(FILE))

OBJ_DIR		=	./obj
OBJS		=	$(addprefix $(OBJ_DIR)/, $(patsubst %.cpp,%.o,$(FILE)))

# var ==================================================

CXX         =	c++
CXXFLAGS    =	-Wall -Werror -Wextra -std=c++98 $(INCLUDE)
# CXXFLAGS    =	-Wall -Werror -Wextra -std=c++98 $(INCLUDE) -g -fsanitize=address
# CXXFLAGS    =	-Wall -Werror -Wextra -std=c++11 $(INCLUDE) -g -fsanitize=address

# Rule =================================================

.PHONY	: all
all		: $(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo $(YELLOW)"Compiling... $<"$(RESET)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $@ $^
	@echo $(GREEN)"Done!"$(RESET)

.PHONY	: clean
clean	:
	@echo $(RED)"Remove $(OBJ_DIR)..."$(RESET)
	@rm -rf $(OBJ_DIR)

.PHONY	: fclean
fclean	:
	@make clean
	@echo $(RED)"Remove $(NAME)..."$(RESET)
	@rm -f $(NAME)

.PHONY	: re
re		:
	@make fclean
	@make all
