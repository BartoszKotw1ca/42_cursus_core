NAME = btc
SRC = main.cpp BitcoinExchange.cpp
# OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++98 -Wall -Wextra -Werror
COMPILER = g++

$(NAME): $(OBJ)
	$(COMPILER) $(FLAGS) $(SRC) -o $(NAME)

all: $(NAME)
	./btc input.csv

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

# .cpp.o:
# 	$(COMPILER) $(FLAGS) -c $< -o $@

.PHONY: all clean fclean re
