SRCS_COMMON = ./utils/exit_functions.c \
	./utils/parse_arguments.c \
	./utils/get_stack.c \
	./utils/get_next_node.c \
	./utils/assert_stack_needs_sorting.c \
	./utils/output_stack.c \
	./pusw_operators/pusw_tools_p.c \
	./pusw_operators/pusw_tools_rr.c \
	./pusw_operators/pusw_tools_rrr.c \
	./pusw_operators/pusw_tools_ss.c

NAME = push_swap
INCLUDES = ./push_swap.h
SRCS = $(SRCS_COMMON) ./push_swap.c \
	./sort_functions/count_stack_elems.c \
	./sort_functions/sort_stack.c \
	./sort_functions/merge_sort.c \
	./sort_functions/simple_sort.c
OBJS = $(SRCS:%.c=%.o)

NAME_BONUS = push_swap_bonus
INCLUDES_BONUS = ./bonus/push_swap_bonus.h
SRCS_BONUS = $(SRCS_COMMON) ./bonus/push_swap_bonus.c \
	./bonus/perform_than_verify_pusw_bonus.c
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc $(CFLAGS)
RM = rm -rf

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

bonus: $(NAME) $(NAME_BONUS)

%.o: %.c $(INCLUDES) $(INCLUDES_BONUS)
	$(CC) -c $< -o $(<:%.c=%.o) -I$(LIBFT)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_PATH) -lft

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

test: bonus test_simple test_intermidiate test_advanced

retest: re test

norminette:
	@echo "\nNORMINETTE:"; norminette

test_simple:
	@echo "\nSIMPLE TEST"
	@echo -n "checker_linux: "
	@ARG=$$(cat ./test_simple.txt); ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	-@ARG=$$(cat ./test_simple.txt); ./push_swap $$ARG | ./push_swap_bonus $$ARG
	@echo -n "Operations: "
	@ARG=$$(cat ./test_simple.txt); ./push_swap $$ARG | wc -l

test_intermidiate:
	@echo "\nSIMPLE TEST"
	@echo -n "checker_linux: "
	@ARG=$$(cat ./test_intermidiate.txt); ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	-@ARG=$$(cat ./test_intermidiate.txt); ./push_swap $$ARG | ./push_swap_bonus $$ARG
	@echo -n "Operations: "
	@ARG=$$(cat ./test_intermidiate.txt); ./push_swap $$ARG | wc -l

test_advanced:
	@echo "\nSIMPLE TEST"
	@echo -n "checker_linux: "
	@ARG=$$(cat ./test_advanced.txt); ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	-@ARG=$$(cat ./test_advanced.txt); ./push_swap $$ARG | ./push_swap_bonus $$ARG
	@echo -n "Operations: "
	@ARG=$$(cat ./test_advanced.txt); ./push_swap $$ARG | wc -l

.PHONY: all bonus clean fclean re test retest