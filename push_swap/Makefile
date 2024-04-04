FLAGS = -Wall -Wextra -Werror
LIB = ./mylibft/mylibft.a
NAME = push_swap

SRC = operations.c main_function.c

OBJ := $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): mylibft/mylibft.a $(OBJ)
	cc $(FLAGS) $^ -o $@ $(LIB)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

mylibft/mylibft.a:
	make -C mylibft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C mylibft fclean

re: fclean all

.PHONY: all, clean, fclean, re
