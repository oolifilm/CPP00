# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/25 21:13:44 by leaugust          #+#    #+#              #
#    Updated: 2025/08/28 18:53:24 by leaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook
CC	 = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC_DIR =
OBJ_DIR = obj/
INC_DIR = include/

RESET		= \033[0m
PURPLE		= \033[38;5;183m
PINK		= \033[38;5;218m
BLUE		= \033[38;5;153m
UP			= \033[A
CUT			= \033[K

SRC_FILES = Contact.class.cpp main.cpp PhoneBook.class.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)

SRC_PATH = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_PATH = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(NAME)
	@printf "$(BLUE)Welcome to EX01 of CPP00\n$(RESET)"

$(NAME): $(OBJ_PATH)
	@echo "$(PURPLE)Compiling [$(NAME)]...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_PATH) -o $(NAME)
	@echo "$(PINK)Finished [$(NAME)]$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@echo "$(PURPLE)Compiling [$@]...$(RESET)"
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(CUT)"
	@echo "$(PINK)Finished [$@]$(RESET)"
	@printf "$(UP)$(CUT)"

clean:
	@if [ -d "$(OBJ_DIR)" ]; then \
	rm -rf $(OBJ_DIR); \
	echo "$(BLUE)Deleting all objects from /ex01...$(RESET)"; else \
	echo "No objects to remove from /ex01."; \
	fi;

fclean: clean
	@if [ -f "$(NAME)" ]; then \
	rm -f $(NAME); \
	echo "$(BLUE)Deleting $(NAME) from ex01...$(RESET)"; else \
	echo "No Executable to remove from ex01."; \
	fi;

re: fclean all

.PHONY: all clean fclean re