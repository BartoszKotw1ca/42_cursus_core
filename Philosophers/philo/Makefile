FLAGS = -Wall -Wextra -Werror -g -pthread
NAME = philo
SRC = main.c ft_atoilong.c utils.c check_data.c write_data.c create_philos.c philo_routine.c for_one.c
OBJDIR = Obj/
OBJ := $(SRC:%.c=$(OBJDIR)%.o)

all: $(NAME)
	@echo "Compilation completed."

$(NAME): $(OBJ)
	@cc $(FLAGS) $^ -o $@

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	@cc $(FLAGS) -c $< -o $@

%.o: %.c
	@cc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJDIR)
	@echo "Cleared."

re: fclean all

.PHONY: all, clean, fclean, re
