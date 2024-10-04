NAME = PmergeMe
SRC = main.cpp PmergeMe.cpp
# OBJ = $(SRC:.cpp=.o)
FLAGS =  -g
COMPILER = g++

$(NAME): $(OBJ)
	@$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	./PmergeMe "1, 2, 3, 4, 12, 43"
	@echo

clean:
	@-rm -f $(OBJ)

fclean: clean
	@-rm -f $(NAME)

re: fclean all

# .cpp.o:
# 	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
