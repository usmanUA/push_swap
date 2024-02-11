flags = -Wall -Wextra -Werror
LIBFT = libft.a
NAME = push_swap
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FILES = push_swap.c\
		create_stack.c \
		int_array.c \
		sort_small.c \
		push_to_b.c \
		push_to_b_utils.c \
		instructions.c \
		instructions_utils.c \
		instructions_more_utils.c \
		stack_utils.c \
		push_to_a.c \
		push_to_a_utils.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@[ -f $(NAME) ] || (echo "$(GREEN)Creating The Executable:   $(NAME)$(RESET)" && cc $(OBJS) libft/$(LIBFT) -o $(NAME))
	
%.o: %.c
	@[ -f $@ ] || (echo "$(GREEN)Creating Object File: $@$(RESET)" && cc -g $(flags) -c $< -o $@)
	
$(LIBFT):
	@$(MAKE) -C libft

clean:
	@echo "$(RED)Cleaning Object Files for libft and push_swap$(RESET)"
	@$(MAKE) -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@echo "$(RED)Removing   $(LIBFT) and $(NAME)$(RESET)"
	@rm -rf libft/$(LIBFT)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
