NAME = push_swap
INCLUDES = ./push_swap.h
SRCS = ./push_swap.c \
	./pusw_utils/pusw_get_array.c \
	./pusw_utils/pusw_get_stack.c \
	./pusw_utils/pusw_output_stack.c \
	./pusw_sort_functions/pusw_perform_radix.c \
	./pusw_sort_functions/pusw_tools_p.c \
	./pusw_sort_functions/pusw_tools_rr.c \
	./pusw_sort_functions/pusw_tools_rrr.c \
	./pusw_sort_functions/pusw_tools_ss.c
OBJS = $(SRCS:%.c=%.o)

NAME_BONUS = push_swap_bonus
INCLUDES_BONUS = ./pusw_bonus/push_swap_bonus.h
SRCS_BONUS = ./pusw_bonus/push_swap_bonus.c \
	./pusw_bonus/pusw_get_array_bonus.c
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

test: all test1 test2 test3 test4 test5 test6 test7
	$(RM) tests/output*
	echo "\nALL TESTS PASSED"

retest: re test

test1:
	-./push_swap -01 442 2147483647 > tests/output1.txt
	diff tests/correct1.txt tests/output1.txt
test2:
	-./push_swap -01 442 2147483648 > tests/output2.txt
	diff tests/correct2.txt tests/output2.txt
test3:
	-./push_swap -01 442 -2147483648 > tests/output3.txt
	diff tests/correct3.txt tests/output3.txt
test4:
	-./push_swap -01 442 -2147483649 > tests/output4.txt
	diff tests/correct4.txt tests/output4.txt
test5:
	-./push_swap -01 442 2147483647 442 > tests/output5.txt
	diff tests/correct5.txt tests/output5.txt
test6:
	-./push_swap -01 442 2147483647 -1 > tests/output6.txt
	diff tests/correct6.txt tests/output6.txt
test7:
	-./push_swap -01 442 2147483647 -0001 > tests/output7.txt
	diff tests/correct7.txt tests/output7.txt


.PHONY: all bonus clean fclean re teste retest