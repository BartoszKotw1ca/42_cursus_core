NAME = PmergeMe
SRC = PmergeMe.cpp main.cpp
FLAGS = -g -Wall -Wextra -Werror -std=c++98
COMPILER = g++

$(NAME): $(OBJ)
	@$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

test:
	# Test for sorted == Error
	-./PmergeMe 1 2 3 4
	# Test for only one arg == Error
	-./PmergeMe
	# Test for 2 same values == Error
	./PmergeMe 2 3 4 "3" 1

all: $(NAME)
	-./PmergeMe `shuf -i 1-1000000 -n 10000 | tr "\n" " "`
	@echo

clean:
	@-rm -f $(OBJ)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

# .cpp.o:
# 	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
