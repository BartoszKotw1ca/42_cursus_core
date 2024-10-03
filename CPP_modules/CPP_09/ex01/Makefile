NAME = RPN
SRC = main.cpp RPN.cpp
# OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++98 -Wall -Wextra -Werror -g
COMPILER = g++

$(NAME): $(OBJ)
	@$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" #42
	./RPN "7 7 * 7 -"#42
	./RPN "1 2 * 2 / 2 * 2 4 - +" #0
	./RPN "(1 + 1)" #Error
	./RPN "1 + 1" #Error
	./RPN "20 +" #2
	./RPN "1 + 11" #Error
	./RPN "5 1 2 + 4 * + 3 -" #14
	./RPN "8 3 5 * 6 2 / + - 4 +" #-6
	./RPN "15 7 1 1 + - / 3 * 2 1 1 + + -"
	@echo

clean:
	@-rm -f $(OBJ)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

# .cpp.o:
# 	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
