NAME = push_swap

INCLUDES = push_swap.h
SRCS = push_swap.c \
	./input_utils/ps_args_validation.c \
	./input_utils/ps_common_tools.c
OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror -g
CC = cc $(CFLAGS)
RM = rm -rf

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

all: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft

%.o: %.c $(INCLUDES)
	$(CC) -c $< -o $(<:%.c=%.o) -I$(LIBFT)

$(LIBFT):
	make -C $(LIBFT_PATH) all

clean:
	make -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re