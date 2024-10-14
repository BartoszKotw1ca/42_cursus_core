NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
FLAGS = -g -Wall -Wextra -Werror -std=c++98
COMPILER = g++

$(NAME): $(OBJ)
	@$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	./PmergeMe
	@echo

clean:
	@-rm -f $(OBJ)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

# .cpp.o:
# 	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
