NAME = RPN
SRC = main.cpp RPN.cpp
# OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++98 -Wall -Wextra -Werror
COMPILER = g++

$(NAME): $(OBJ)
	@$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	./RPN "7 7 * 7 -"
	./RPN "1 2 * 2 / 2 * 2 4 - +"
	./RPN "(1 + 1)"
	@echo

clean:
	@-rm -f $(OBJ)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

# .cpp.o:
# 	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
