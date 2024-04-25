FLAGS = -Wall -Wextra -Werror
LIB = ./mylibft/mylibft.a
NAME = push_swap
OBJDIR = Obj/

SRC =	utilis/correct_data.c \
	utilis/ft_atoilong.c \
	utilis/operations.c \
	utilis/utils.c \
	utilis/utils_2.c \
	algorithm/for_two_num.c \
	algorithm/for_three_num.c \
	algorithm/for_four_numbers.c \
	algorithm/algorithm_utils.c \
	algorithm/algorithm_utils1.c \
	algorithm/algorithm_main.c \
	main.c

OBJ := $(SRC:%.c=$(OBJDIR)%.o)

all: $(NAME)
	@echo "Compilation completed."

$(NAME): mylibft/mylibft.a $(OBJ)
	@cc $(FLAGS) $^ -o $@ $(LIB)

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	@cc $(FLAGS) -c $< -o $@

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

mylibft/mylibft.a:
	@make -s -C mylibft

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@make -s -C mylibft fclean
	@rm -rf $(OBJDIR)
	@echo "Cleared."

re: fclean all

.PHONY: all, clean, fclean, re
