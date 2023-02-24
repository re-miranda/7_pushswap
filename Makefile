SRCS_COMMON = ./utils/exit_functions.c \
	./utils/parse_arguments.c \
	./utils/get_stack.c \
	./utils/get_next_node.c \
	./utils/assert_stack_needs_sorting.c \
	./pusw_operators/pusw_tools_p.c \
	./pusw_operators/pusw_tools_rr.c \
	./pusw_operators/pusw_tools_rrr.c \
	./pusw_operators/pusw_tools_ss.c

NAME = push_swap
INCLUDES = ./push_swap.h
SRCS = $(SRCS_COMMON) ./push_swap.c \
	./sort_functions/count_stack_elems.c \
	./sort_functions/push_and_count.c \
	./sort_functions/find_middle_value.c \
	./sort_functions/sort_stack.c \
	./sort_functions/merge_sort.c \
	./sort_functions/simple_sort.c
OBJS = $(SRCS:%.c=%.o)

NAME_BONUS = push_swap_bonus
INCLUDES_BONUS = ./bonus/push_swap_bonus.h
SRCS_BONUS = $(SRCS_COMMON) ./bonus/push_swap_bonus.c \
	./bonus/perform_than_verify_pusw_bonus.c \
	./bonus/exit_functions_bonus.c
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

VAL_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes -s -q
VAL = valgrind $(VAL_FLAGS)
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

test: norminette test_simple test_intermidiate test_advanced test_error

retest: re test

norminette:
	@echo "\nNORMINETTE:"; norminette

test_simple: bonus
	@echo "\nSIMPLE TEST"
	@echo -n "checker_linux: "
	@ARG=$$(cat ./test_simple.txt); ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	@ARG=$$(cat ./test_simple.txt); ./push_swap $$ARG | ./push_swap_bonus $$ARG
	@echo -n "Operations: "
	@ARG=$$(cat ./test_simple.txt); ./push_swap $$ARG | wc -l

test_intermidiate: bonus
	@echo "\nINTERMIDIATE TEST"
	@echo -n "checker_linux: "
	@ARG=$$(cat ./test_intermidiate.txt); ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	@ARG=$$(cat ./test_intermidiate.txt); ./push_swap $$ARG | ./push_swap_bonus $$ARG
	@echo -n "Operations: "
	@ARG=$$(cat ./test_intermidiate.txt); ./push_swap $$ARG | wc -l

test_advanced: bonus
	@echo "\nADVANCED TEST"
	@echo -n "checker_linux: "
	@ARG=$$(cat ./test_advanced.txt); ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	@ARG=$$(cat ./test_advanced.txt); ./push_swap $$ARG | ./push_swap_bonus $$ARG
	@echo -n "Operations: "
	@ARG=$$(cat ./test_advanced.txt); ./push_swap $$ARG | wc -l

test_error: bonus
	@echo "\nERROR TEST"
	-@echo "\nnon_numeric_0"; ARG=$$(cat ./non_numeric_0.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nnon_numeric_1"; ARG=$$(cat ./non_numeric_1.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nnon_numeric_2"; ARG=$$(cat ./non_numeric_2.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nnon_numeric_3"; ARG=$$(cat ./non_numeric_3.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nnon_numeric_4"; ARG=$$(cat ./non_numeric_4.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nnon_numeric_5"; ARG=$$(cat ./non_numeric_5.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nduplicate_number_0"; ARG=$$(cat ./duplicate_number_0.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nduplicate_number_1"; ARG=$$(cat ./duplicate_number_1.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nduplicate_number_2"; ARG=$$(cat ./duplicate_number_2.txt); $(VAL) ./push_swap $$ARG
	@echo -n "\nchecker_linux: "
	@echo "max_int"; ARG=$$(cat ./max_int.txt); $(VAL) ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	@echo "max_int"; ARG=$$(cat ./max_int.txt); ./push_swap $$ARG | $(VAL) ./push_swap_bonus $$ARG
	@echo -n "\nchecker_linux: "
	@echo "min_int"; ARG=$$(cat ./min_int.txt); $(VAL) ./push_swap $$ARG | ./checker_linux $$ARG
	@echo -n "checker_bonus: "
	@echo "min_int"; ARG=$$(cat ./min_int.txt); ./push_swap $$ARG |  $(VAL) ./push_swap_bonus $$ARG
	-@echo "\nmax_int_overflow"; ARG=$$(cat ./max_int_overflow.txt); $(VAL) ./push_swap $$ARG
	-@echo "\nmin_int_overflow"; ARG=$$(cat ./min_int_overflow.txt); $(VAL) ./push_swap $$ARG
	@echo "\n2 1 0"; ARG="2 1 0"; $(VAL) ./push_swap $$ARG | ./checker_linux $$ARG

.PHONY: all bonus clean fclean re test retest